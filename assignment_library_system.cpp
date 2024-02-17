#include <iostream>
#include <string>

using namespace std;

// Define the structure for a book
struct Book {
    string title;
    string author;
    int year;
    Book* next; // Pointer to the next book in the list

    // Constructor
    Book(string t, string a, int y) : title(t), author(a), year(y), next(nullptr) {}
};

class LibraryCatalog {
private:
    Book* head; // Pointer to the first book in the list

public:
    // Constructor
    LibraryCatalog() : head(nullptr) {}

    // Destructor to free memory
    ~LibraryCatalog() {
        Book* current = head;
        while (current != nullptr) {
            Book* next = current->next;
            delete current;
            current = next;
        }
    }

    // Add a book to the catalog
    void addBook(string title, string author, int year) {
        Book* newBook = new Book(title, author, year);
        if (head == nullptr) {
            head = newBook;
        } else {
            Book* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newBook;
        }
        cout << "Book added: " << title << endl;
    }

    // Search for a book by title
    void searchByTitle(string title) {
        Book* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->title == title) {
                cout << "Book found: " << current->title << " by " << current->author << ", " << current->year << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            cout << "Book not found with title: " << title << endl;
        }
    }

    // Search for a book by author
    void searchByAuthor(string author) {
        Book* current = head;
        bool found = false;
        while (current != nullptr) {
            if (current->author == author) {
                cout << "Book found: " << current->title << " by " << current->author << ", " << current->year << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) {
            cout << "Book not found by author: " << author << endl;
        }
    }
};

int main() { 
    LibraryCatalog library;
    int choice;
    string title, author;
    int year;

    do {
        cout << "\nLibrary Management System Menu" << endl;
        cout << "1. Add a Book" << endl;
        cout << "2. Search by Title" << endl;
        cout << "3. Search by Author" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the title of the book: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter the author of the book: ";
                getline(cin, author);
                cout << "Enter the year of publication: ";
                cin >> year;
                library.addBook(title, author, year);
                break;
            case 2:
                cout << "Enter the title to search: ";
                cin.ignore();
                getline(cin, title);
                library.searchByTitle(title);
                break;
            case 3:
                cout << "Enter the author to search: ";
                cin.ignore();
                getline(cin, author);
                library.searchByAuthor(author);
                break;
            case 4:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
