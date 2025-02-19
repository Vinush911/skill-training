#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

// Function prototype
void reverseWords(char str[]);

int main() {
    char str[MAX_LENGTH];

    // Read a sentence from the user
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove the newline character if present
    str[strcspn(str, "\n")] = 0;

    // Reverse the words in the sentence
    reverseWords(str);

    // Print the reversed sentence
    printf("Reversed Sentence: %s\n", str);

    return 0;
}

// Function to reverse each word in the sentence
void reverseWords(char str[]) {
    int start = 0, end = 0;
    int length = strlen(str);

    // Reverse each word in the string
    while (end <= length) {
        // Find the end of the current word
        if (str[end] == ' ' || str[end] == '\0') {
            // Reverse the current word
            int wordEnd = end - 1;
            while (start < wordEnd) {
                char temp = str[start];
                str[start] = str[wordEnd];
                str[wordEnd] = temp;
                start++;
                wordEnd--;
            }
            // Move to the next word
            start = end + 1;
        }
        end++;
    }
}
