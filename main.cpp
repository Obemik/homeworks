#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>

using namespace std;

class Library {
private:
    map<string, vector<string>> books;

public:
    void addBook(const string& title, const vector<string>& authors) {
        books[title] = authors;
    }

    void searchAuthors(const string& title) {
        if (books.find(title) != books.end()) {
            cout << "Authors of the book \"" << title << "\":\n";
            for (const auto& author : books[title]) {
                cout << author << endl;
            }
        }
        else {
            cout << "Book not found.\n";
        }
    }

    void displayBooks() {
        for (auto it = books.begin(); it != books.end(); ++it) {
            cout << it->first << " — ";
            for (size_t i = 0; i < it->second.size(); ++i) {
                cout << it->second[i];
                if (i < it->second.size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a book\n";
        cout << "2. Search authors by book title\n";
        cout << "3. Display all books\n";
        cout << "4. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string title;
            cout << "Enter book title: ";
            getline(cin, title);

            cout << "Enter authors (separate by commas): ";
            string authorsLine;
            getline(cin, authorsLine);
            stringstream ss(authorsLine);
            vector<string> authors;
            string author;
            while (getline(ss, author, ',')) {
                authors.push_back(author);
            }

            library.addBook(title, authors);
            cout << "Book added!\n";
        }
        else if (choice == 2) {
            string title;
            cout << "Enter book title to search for authors: ";
            getline(cin, title);
            library.searchAuthors(title);
        }
        else if (choice == 3) {
            cout << "List of all books:\n";
            library.displayBooks();
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
