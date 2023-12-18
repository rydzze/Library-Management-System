#include <iostream>
#include <cstdlib>
#include "LibrarySys.hpp"
using namespace std;
using System::Library;

void init(Library& library);

int main(){

    Library library;
    init(library);
    
    string title, author, genre, publisher;
    int id, year;
    long long int ISBN;
    
    int choice = 0;
    do{
        system("cls");
        //change menu interface
        cout << "\nLibrary Management System\n";
        cout << "\n1. Add book";
        cout << "\n2. Edit book";
        cout << "\n3. Search book";
        cout << "\n4. Display book";
        cout << "\n5. Delete book";
        
        cout << "\n\n0. Exit System";

        cout << "\n\nInput: ";
        cin >> choice;
        cin.ignore();

        system("cls");
        switch(choice){
            case 1:
                cout << "\nTitle : ";
                getline(cin, title);
                cout << "\nAuthor: ";
                getline(cin, author);
                cout << "\nGenre : ";
                getline(cin, genre);
                cout << "\nYear  : ";
                cin >> year;
                cout << "\nISBN  : ";
                cin >> ISBN;
                cin.ignore();
                cout << "\nPublisher  : ";
                getline(cin, publisher);
                id = 1000 + library.getTotalBook();

                library.addBook(id, title, author, genre, year, ISBN, publisher);
                break;
            
            case 2:
                void displayBook(ID);
                //display semua buku
                cout << "\nEnter Book ID: ";
                cin >> ID;
                //search for the books
                cout<<"\nEditing book with ID "<< current->ID << endl;
                //found the book
                cout << "\nTitle : ";
                getline(cin, title);
                cout << "\nAuthor: ";
                getline(cin, author);
                cout << "\nGenre : ";
                getline(cin, genre);
                cout << "\nYear  : ";
                cin >> year;
                cout << "\nISBN  : ";
                cin >> ISBN;
                cin.ignore();
                cout << "\nPublisher  : ";
                getline(cin, publisher);
                // get the new input for the book from the user
                id = 1000 + library.getTotalBook();
                library.editBook(id, title, author, genre, year, ISBN, publisher);
                break;
            case 3:
                //search
                break;
            case 4:
                //display
                break;
            case 5:
                //delete
                break;
            case 0:
                cout << "\nExit ...\n";
                break;
            default:
                break;
        }

    }while(choice != 0);

    system("pause");
    return 0;
}

void init(Library& library){
    library.addBook(1001, "The Great Gatsby", "F. Scott Fitzgerald", "Fiction", 1925, 9781234567890, "Scribner");
    library.addBook(1002, "To Kill a Mockingbird", "Harper Lee", "Fiction", 1960, 9780061120084, "J.B. Lippincott");
    library.addBook(1003, "1984", "George Orwell", "Dystopian", 1949, 9780451524935, "Secker & Warburg");
    library.addBook(1004, "Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "Fantasy", 1997, 9780590353427, "Scholastic");
    library.addBook(1005, "The Catcher in the Rye", "J.D. Salinger", "Fiction", 1951, 9780241950432, "Little, Brown and Company");
}
