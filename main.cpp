#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable;
};


void Menu() {
    cout << "**** LIBRARY MANAGEMENT SYSTEM ****"<<endl;
    cout << "1. Add a Book"<< endl;
    cout << "2. Search for a Book"<< endl;
    cout << "3. Check Out a Book"<< endl;
    cout << "4. Return a Book"<< endl;
    cout << "5. Display All Books"<< endl;
    cout << "6. Exit"<< endl;
    cout << "****Enter your choice: "<< endl;
}


void addBook(vector<Book>& books) {
    Book newBook;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, newBook.title);
    cout << "Enter book author: ";
    getline(cin, newBook.author);
    cout << "Enter book ISBN: ";
    getline(cin, newBook.isbn);
    newBook.isAvailable = true;
    books.push_back(newBook);
    cout << "Book added successfully!" << endl;
}


void searchBook(const vector<Book>& books) {
    string query;
    cout << "Enter title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, query);

    bool found = false;
    for (const auto& book : books) {
        if (book.title == query || book.author == query || book.isbn == query) {
            cout << "Book Found:\n";
            cout << "Title: " << book.title << "\n";
            cout << "Author: " << book.author << "\n";
            cout << "ISBN: " << book.isbn << "\n";
            cout << "Status: " << (book.isAvailable ? "Available" : "Checked Out") << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "book not available .\n";
    }
}


void checkOutBook(vector<Book>& books) {
    string isbn;
    cout << "Enter ISBN of the book to check out: ";
    cin.ignore();
    getline(cin, isbn);

    for (auto& book : books) {
        if (book.isbn == isbn) {
            if (book.isAvailable) {
                book.isAvailable = false;
                cout << "Book checked out successfully!\n";
                return;
            } else {
                cout << "Book is already checked out.\n";
                return;
            }
        }
    }

    cout << "Book not found.\n";
}


void returnBook(vector<Book>& books) {
    string isbn;
    cout << "Enter your book ISBN to return: ";
    cin.ignore();
    getline(cin, isbn);

    for (auto& book : books) {
        if (book.isbn == isbn) {
            if (!book.isAvailable) {
                book.isAvailable = true;
                cout << "Book returned successfully!"<< endl;
                return;
            } else {
                cout << "Book was not checked out."<< endl;
                return;
            }
        }
    }

    cout << "Book not found."<< endl;
}


void displayBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books available."<< endl;
        return;
    }

    cout << left << setw(30) << "Title" << setw(20) << "Author" << setw(15) << "ISBN" << "Status\n";
    cout << "_________________________________________________________________________________________" << endl;
    for (const auto& book : books) {
        cout << left << setw(30) << book.title
             << setw(20) << book.author
             << setw(15) << book.isbn
             << (book.isAvailable ? "Available" : "Checked Out") << "\n";
    }
}


int main() {
    vector<Book> books;
    int choice;

    do {
        Menu();
        cin >> choice;

        switch (choice) {
            case 1:
                addBook(books);
                break;

            case 2:
                searchBook(books);
                break;

            case 3:
                checkOutBook(books);
                break;

            case 4:
                returnBook(books);
                break;

            case 5:
                displayBooks(books);
                break;

            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again."<< endl;
        }

        cout << endl;
    } while (choice != 6);

    return 0;
}
