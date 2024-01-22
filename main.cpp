// g++ -o LibraryManagementSystem main.cpp Library.cpp Membership.cpp

#include <iostream>
#include <cstdlib>
#include "Library.hpp"
#include "Membership.hpp"
using namespace std;
using LibSys::Library;
using MemberSys::Membership;

void init(Library& library, Membership& member);

int main(){

    Library library;
    Membership member;
    init(library, member);
    
    string userInput = "";
    int choice = 0;
    bool proceed;

    do{
        system("cls");
        cout << "\n **************************************************************************\n\n";
        cout << "                      WELCOME TO LIBRARY MANAGEMENT SYSTEM                   \n";
        cout << "                                   MAIN MENU                                 \n";
        cout << "\n **************************************************************************\n\n";
        cout << "\n\t1.  Add new book";
        cout << "\n\t2.  View book info";
        cout << "\n\t3.  Edit book info";
        cout << "\n\t4.  Display all books";
        cout << "\n\t5.  Delete existing book\n";

        cout << "\n\t6.  Add new member";
        cout << "\n\t7.  Display all members";
        cout << "\n\t8.  Edit member info";
        cout << "\n\t9.  Delete existing member\n";

        cout << "\n\t10. Borrow a book";
        cout << "\n\t11. Return a book\n";

        cout << "\n\t12. Load data";
        cout << "\n\t13. Save data";
        
        cout << "\n\n\t0.  Exit System\n";

        cout << "\n\n    Input: ";
        cin >> choice;
        cin.ignore();

        system("cls");
        switch(choice){
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayAllBook();
                library.viewBookInfo();
                break;
            case 3:
                library.displayAllBook();
                library.editBook();
                break;
            case 4:
                library.displayAllBook();
                break;
            case 5:
                library.displayAllBook();
                library.deleteBook();
                break;
            case 6:
                member.addMember();
                break;
            case 7:
                member.displayAllMember();
                break;
            case 8:
                member.displayAllMember();
                member.editMember();
                break;
            case 9:
                member.displayAllMember();
                member.deleteMember();
                break;
            case 10:
                cout << "\nEnter Member ID : ";
                cin >> userInput;
                proceed = member.checkMembership(userInput);
                if(proceed){
                    library.borrowBook(userInput, member.getName(userInput));
                }
                break;
            case 11:
                library.returnBook();
                break;
            case 12:
                library.deleteAllBook();
                member.deleteAllMember();
                library.loadFile();
                member.loadFile();
                break;
            case 13:
                library.saveFile();
                member.saveFile();
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

void init(Library& library, Membership& member){
    library.loadFile();
    member.loadFile();
}
