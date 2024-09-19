#include <iostream>
#include <string>
using namespace std;

// Structure for a Book in the library
struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
    Book* next; // Pointer to the next book (Linked List)

    // Constructor to initialize the book
    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
        next = NULL;  // Using NULL instead of nullptr
    }
};

// Structure for a User in the system
struct User {
    int id;
    string name;
    User* next; // Pointer to the next user (Linked List)

    // Constructor to initialize the user
    User(int userId, string userName) {
        id = userId;
        name = userName;
        next = NULL;  // Using NULL instead of nullptr
    }
};

// Class representing the Library
class Library {
private:
    Book* headBook;  // Head pointer for the list of books
    User* headUser;  // Head pointer for the list of users

public:
    Library() {
        headBook = NULL;  // Initialize with NULL
        headUser = NULL;  // Initialize with NULL
    }

    // Function to add a new book to the library (Insert at end)
    void addBook(int id, string title, string author) {
        Book* newBook = new Book(id, title, author);
        if (headBook == NULL) {
            headBook = newBook;
        } else {
            Book* temp = headBook;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newBook;
        }
        cout << "Book added: " << title << " by " << author << endl;
    }

    // Function to add a new user to the system
    void addUser(int id, string name) {
        User* newUser = new User(id, name);
        if (headUser == NULL) {
            headUser = newUser;
        } else {
            User* temp = headUser;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newUser;
        }
        cout << "User added: " << name << endl;
    }

    // Function to issue a book to a user
    void issueBook(int bookId) {
        Book* book = searchBook(bookId);
        if (book == NULL) {
            cout << "Book not found!" << endl;
        } else if (book->isIssued) {
            cout << "Book already issued!" << endl;
        } else {
            book->isIssued = true;
            cout << "Book " << book->title << " issued successfully!" << endl;
        }
    }

    // Function to return a book
    void returnBook(int bookId) {
        Book* book = searchBook(bookId);
        if (book == NULL) {
            cout << "Book not found!" << endl;
        } else if (!book->isIssued) {
            cout << "Book was not issued!" << endl;
        } else {
            book->isIssued = false;
            cout << "Book " << book->title << " returned successfully!" << endl;
        }
    }

    // Function to search for a book by its ID
    Book* searchBook(int bookId) {
        Book* temp = headBook;
        while (temp != NULL) {
            if (temp->id == bookId) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL; // Book not found
    }

    // Function to display all books in the library
    void displayBooks() {
        if (headBook == NULL) {
            cout << "No books in the library." << endl;
            return;
        }
        Book* temp = headBook;
        while (temp != NULL) {
            cout << "Book ID: " << temp->id << ", Title: " << temp->title
                 << ", Author: " << temp->author
                 << ", Status: " << (temp->isIssued ? "Issued" : "Available") << endl;
            temp = temp->next;
        }
    }

    // Function to display all users in the system
    void displayUsers() {
        if (headUser == NULL) {
            cout << "No users in the system." << endl;
            return;
        }
        User* temp = headUser;
        while (temp != NULL) {
            cout << "User ID: " << temp->id << ", Name: " << temp->name << endl;
            temp = temp->next;
        }
    }
};

// Main function to handle user input
int main() {
    Library lib;
    int choice;

    while (true) {
        cout << "\n----- Library Management System -----\n";
        cout << "1. Add Book\n";
        cout << "2. Add User\n";
        cout << "3. Display Books\n";
        cout << "4. Display Users\n";
        cout << "5. Issue Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int bookId;
            string title, author;
            cout << "Enter book ID: ";
            cin >> bookId;
            cin.ignore();  // To ignore newline character after entering the ID
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter book author: ";
            getline(cin, author);
            lib.addBook(bookId, title, author);
        } else if (choice == 2) {
            int userId;
            string name;
            cout << "Enter user ID: ";
            cin >> userId;
            cin.ignore();  // To ignore newline character after entering the ID
            cout << "Enter user name: ";
            getline(cin, name);
            lib.addUser(userId, name);
        } else if (choice == 3) {
            cout << "\nBooks in the library:\n";
            lib.displayBooks();
        } else if (choice == 4) {
            cout << "\nUsers in the system:\n";
            lib.displayUsers();
        } else if (choice == 5) {
            int bookId;
            cout << "Enter book ID to issue: ";
            cin >> bookId;
            lib.issueBook(bookId);
        } else if (choice == 6) {
            int bookId;
            cout << "Enter book ID to return: ";
            cin >> bookId;
            lib.returnBook(bookId);
        } else if (choice == 7) {
            cout << "Exiting system...\n";
            break;
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
