#include <iostream>
#include <cstdlib>
#include "LibrarySys.hpp"
using namespace std;
using System::Library;

void init(Library& library);

int main(){

    Library library;
    init(library);
    
    string id, title, author, genre, publisher;
    int year;
    long long int ISBN;
    
    int choice = 0;
    do{
        system("cls");
        //change menu interface
        cout << "\n**************************************************************************\n";
        cout << "                     WELCOME TO LIBRARY MANAGEMENT SYSTEM                   \n";
        cout << "                                  MAIN MENU                                 \n";
        cout << "\n**************************************************************************\n\n";
        cout << "\n1. Add new book";
        cout << "\n2. Edit book details";
        cout << "\n3. Search book info";
        cout << "\n4. Display all book";
        cout << "\n5. Delete existing book";
        cout << "\n6. Load data from file";
        cout << "\n7. Save data into file";
        
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

                // library.addBook(id, title, author, genre, year, ISBN, publisher);
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
                library.MergeSort();
                library.displayAllBook();
                break;
            case 5:
                library.displayAllBook();
                cout << "\nEnter Book ID: ";
                cin >> id;
                library.deleteBook(id);
                break;
            case 6:
                library.deleteAllBook();
                library.loadFile();
                break;
            case 7:
                library.saveFile();
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
    library.loadFile();
}
