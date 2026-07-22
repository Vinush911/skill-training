/*
1. Functional RequirementsRole Management: 

Two distinct interfaces.

Librarian: Can add/remove/update books, view all users, manage issue/return cycles, and calculate fines.Member: Can log in, search for available books, view personal borrowing history, and check outstanding fine amounts.Book Cataloging: System tracks Book ID, Title, Author, ISBN, Genre, Total Copies, and Available Copies.Search Module: Ability to query the book inventory by Title, Author, or ISBN.Circulation 

System:Checkout: Decrements available book count and records the issue date and calculated due date (e.g., 14 days).Return: Increments available book count and assesses a fee if the book is returned past the due date (e.g., $5 per day).Account/Record Keeping: Generates real-time summary reports (e.g., list of overdue books, total fines collected).
*/


package day2;

// 1. DATA HOLDER: The Book Blueprint
class Book {
    String isbn;
    String title;
    int availableCopies;

    public Book(String isbn, String title, int copies) {
        this.isbn = isbn;
        this.title = title;
        this.availableCopies = copies;
    }
}

// 2. DATA HOLDER: The Member Blueprint
class Member {
    String id;
    String name;
    double fine;

    public Member(String id, String name) {
        this.id = id;
        this.name = name;
        this.fine = 0.0;
    }
}

// 3. ENGINE: Simple Array-Based Library Management
public class StudentsMain {
    
    // Fixed arrays mimic a real-world physical database shelf
    static Book[] catalog = new Book[5];
    static Member[] users = new Member[5];
    
    static int bookCount = 0;
    static int userCount = 0;

    // --- LIBRARIAN ACTIONS ---
    public static void addBook(String isbn, String title, int copies) {
        if (bookCount < catalog.length) {
            catalog[bookCount] = new Book(isbn, title, copies);
            System.out.println("📚 Added: " + title);
            bookCount++;
        }
    }

    // --- MEMBER ACTIONS ---
    public static void searchBook(String title) {
        System.out.println("\n🔍 Searching for: " + title);
        for (int i = 0; i < bookCount; i++) {
            if (catalog[i].title.equalsIgnoreCase(title)) {
                System.out.println("Found! Available copies: " + catalog[i].availableCopies);
                return;
            }
        }
        System.out.println(" Book not found.");
    }

    // --- CIRCULATION MODULE ---
    public static void checkoutBook(String memberId, String isbn) {
        for (int i = 0; i < bookCount; i++) {
            if (catalog[i].isbn.equals(isbn) && catalog[i].availableCopies > 0) {
                catalog[i].availableCopies--; // Decrement inventory count
                System.out.println(" Checkout successful for ISBN: " + isbn);
                return;
            }
        }
        System.out.println(" Checkout failed. Book unavailable.");
    }

    public static void returnBook(String memberId, String isbn, int daysLate) {
        for (int i = 0; i < bookCount; i++) {
            if (catalog[i].isbn.equals(isbn)) {
                catalog[i].availableCopies++; // Increment inventory count
                
                // Fine Calculation Logic
                if (daysLate > 0) {
                    double calculatedFine = daysLate * 5.0; // $5 per day fee
                    System.out.println(" Returned LATE. Fine assessed: $" + calculatedFine);
                } else {
                    System.out.println(" Returned on time.");
                }
                return;
            }
        }
    }

    //  ENGINE STARTING POINT
    public static void main(String[] args) {
        // Simulating Librarian adding books
        addBook("111", "Java Programming", 3);
        addBook("222", "Data Structures", 2);

        // Simulating Member searching and borrowing
        searchBook("Java Programming");
        checkoutBook("M01", "111");
        
        // Confirm inventory dropped down to 2 copies
        searchBook("Java Programming");

        // Simulating Return with a 4-day delay
        returnBook("M01", "111", 4); 
    }
}

