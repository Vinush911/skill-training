import tkinter as tk
import threading
import subprocess
import re
import os
import time
import json

# set your chapters directory
CHAPTERS_DIR = "/Users/vinushkumar/Downloads/novel_chapters"
chapter_files = sorted(f for f in os.listdir(CHAPTERS_DIR) if f.endswith(".txt"))
current_chapter_index = 0

# theme
light_bg = "white"
light_fg = "black"
dark_bg = "#1e1e1e"
dark_fg = "#f0f0f0"
current_theme = "light"

# reading state
pause_flag = False
stop_flag = False
current_sentence_index = 0
speed_multipliers = [1.0, 1.2, 1.5, 2.0]
base_rate = 200

# bookmark file
BOOKMARK_FILE = "bookmark.json"

def save_bookmark(chapter_idx, sentence_idx):
    data = {
        "chapter": chapter_idx,
        "sentence": sentence_idx
    }
    with open(BOOKMARK_FILE, "w") as f:
        json.dump(data, f)

def load_bookmark():
    global current_chapter_index, current_sentence_index
    if os.path.exists(BOOKMARK_FILE):
        with open(BOOKMARK_FILE, "r") as f:
            data = json.load(f)
            current_chapter_index = data.get("chapter", 0)
            current_sentence_index = data.get("sentence", 0)

def clear_bookmark():
    if os.path.exists(BOOKMARK_FILE):
        os.remove(BOOKMARK_FILE)
    print("Bookmark cleared.")

def load_chapter_text(index):
    chapter_path = os.path.join(CHAPTERS_DIR, chapter_files[index])
    with open(chapter_path, "r", encoding="utf-8") as f:
        return f.read()

def render_chapter():
    chapter_text = load_chapter_text(current_chapter_index)
    text_widget.delete("1.0", tk.END)
    text_widget.insert("1.0", chapter_text)

def read_sentences(start_index=0):
    global current_sentence_index
    chapter_text = load_chapter_text(current_chapter_index)
    sentences = re.split(r'(?<=[.!?]) +', chapter_text.strip())
    for idx in range(start_index, len(sentences)):
        if stop_flag:
            break
        while pause_flag:
            time.sleep(0.1)
        current_sentence_index = idx
        save_bookmark(current_chapter_index, current_sentence_index)
        cleaned = sentences[idx].strip()
        if not cleaned:
            continue
        try:
            start_pos = chapter_text.index(sentences[idx])
            end_pos = start_pos + len(sentences[idx])
            start_idx = f"1.0 + {start_pos} chars"
            end_idx = f"1.0 + {end_pos} chars"
            text_widget.tag_remove("highlight", "1.0", tk.END)
            text_widget.tag_add("highlight", start_idx, end_idx)
            text_widget.see(start_idx)
        except ValueError:
            pass
        rate = int(base_rate * float(speed_var.get().replace("x","")))
        subprocess.run(["say", cleaned, "-r", str(rate)])
    text_widget.tag_remove("highlight", "1.0", tk.END)

def start_reading():
    global pause_flag, stop_flag, current_sentence_index
    pause_flag = False
    stop_flag = False
    threading.Thread(target=read_sentences, args=(current_sentence_index,), daemon=True).start()

def pause_reading():
    global pause_flag
    pause_flag = True

def resume_reading():
    global pause_flag
    pause_flag = False

def stop_reading():
    global stop_flag
    stop_flag = True
    text_widget.tag_remove("highlight", "1.0", tk.END)

def next_chapter():
    global current_chapter_index, current_sentence_index
    if current_chapter_index < len(chapter_files) - 1:
        current_chapter_index += 1
        current_sentence_index = 0
        render_chapter()

def prev_chapter():
    global current_chapter_index, current_sentence_index
    if current_chapter_index > 0:
        current_chapter_index -= 1
        current_sentence_index = 0
        render_chapter()

def toggle_theme():
    global current_theme
    if current_theme == "light":
        text_widget.config(bg=dark_bg, fg=dark_fg, insertbackground=dark_fg)
        current_theme = "dark"
    else:
        text_widget.config(bg=light_bg, fg=light_fg, insertbackground="black")
        current_theme = "light"

# GUI
root = tk.Tk()
root.title("Novel Reader with Bookmarks")
root.geometry("800x600")

text_widget = tk.Text(root, wrap="word", font=("Georgia", 14))
text_widget.pack(expand=True, fill="both")
text_widget.tag_configure("highlight", background="lightblue")

frame = tk.Frame(root)
frame.pack(pady=10)

btn_read = tk.Button(frame, text="Read Aloud", command=start_reading)
btn_read.grid(row=0, column=0, padx=5)

btn_pause = tk.Button(frame, text="Pause", command=pause_reading)
btn_pause.grid(row=0, column=1, padx=5)

btn_resume = tk.Button(frame, text="Resume", command=resume_reading)
btn_resume.grid(row=0, column=2, padx=5)

btn_stop = tk.Button(frame, text="Stop", command=stop_reading)
btn_stop.grid(row=0, column=3, padx=5)

btn_prev = tk.Button(frame, text="Previous Chapter", command=prev_chapter)
btn_prev.grid(row=0, column=4, padx=5)

btn_next = tk.Button(frame, text="Next Chapter", command=next_chapter)
btn_next.grid(row=0, column=5, padx=5)

btn_theme = tk.Button(frame, text="Toggle Theme", command=toggle_theme)
btn_theme.grid(row=0, column=6, padx=5)

speed_label = tk.Label(frame, text="Speed:")
speed_label.grid(row=0, column=7, padx=5)

speed_var = tk.StringVar(value="1.0x")
speed_menu = tk.OptionMenu(frame, speed_var, *["1.0x", "1.2x", "1.5x", "2.0x"])
speed_menu.grid(row=0, column=8, padx=5)

btn_clear = tk.Button(frame, text="Clear Bookmark", command=clear_bookmark)
btn_clear.grid(row=0, column=9, padx=5)

# load last bookmark
load_bookmark()
render_chapter()

root.mainloop()
