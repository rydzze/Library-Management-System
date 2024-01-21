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
        cout << "\n **************************************************************************\n\n";
        cout << "                      WELCOME TO LIBRARY MANAGEMENT SYSTEM                   \n";
        cout << "                                   MAIN MENU                                 \n";
        cout << "\n **************************************************************************\n\n";
        cout << "\n\t1. Add new book";
        cout << "\n\t2. Edit book details";
        cout << "\n\t3. Search book info";
        cout << "\n\t4. Display all book";
        cout << "\n\t5. Delete existing book";
        cout << "\n\t6. Load data from file";
        cout << "\n\t7. Save data into file";
        
        cout << "\n\n\t0. Exit System";

        cout << "\n\n\tInput: ";
        cin >> choice;
        cin.ignore();

        system("cls");
        switch(choice){
            case 1:
                library.addBook();
                break;
            
            case 2:
                library.displayAllBook();
                
                library.editBook();
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
                library.deleteBook();
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
