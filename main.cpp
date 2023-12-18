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
        cout << "\n1. Add new book";
        cout << "\n2. Edit book details";
        cout << "\n3. Search book info";
        cout << "\n4. Display all book";
        cout << "\n5. Delete existing book";
        
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
                id = 1001 + library.getTotalBook();

                library.addBook(id, title, author, genre, year, ISBN, publisher);
                break;
            
            case 2:
                library.displayAllBook();
                cout << "\nEnter Book ID: ";
                cin >> id;
                cin.ignore();

                cout<<"\nEditing book with ID "<< id << endl;
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
                
                library.editBook(id, title, author, genre, year, ISBN, publisher);
                break;
            case 3:
                cout << "\nEnter Book ID: ";
                cin >> id;
                library.searchBookInfo(id);
                break;
            case 4:
                library.displayAllBook();
                break;
            case 5:
                library.displayAllBook();
                cout << "\nEnter Book ID: ";
                cin >> id;
                library.deleteBook(id);
                break;
            case 0:
                cout << "\nExit ...\n";
                break;
            default:
                break;
        }
        system("pause");
        
    }while(choice != 0);

    return 0;
}

void init(Library& library){
    library.addBook(1001, "The Great Gatsby", "F. Scott Fitzgerald", "Fiction", 1925, 9781234567890, "Scribner");
    library.addBook(1002, "To Kill a Mockingbird", "Harper Lee", "Fiction", 1960, 9780061120084, "J.B. Lippincott");
    library.addBook(1003, "1984", "George Orwell", "Dystopian", 1949, 9780451524935, "Secker & Warburg");
    library.addBook(1004, "Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "Fantasy", 1997, 9780590353427, "Scholastic");
    library.addBook(1005, "The Catcher in the Rye", "J.D. Salinger", "Fiction", 1951, 9780241950432, "Little, Brown and Company");
}
