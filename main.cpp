// g++ -o LibraryManagementSystem main.cpp Library.cpp Membership.cpp
// g++ -o LibraryManagementSystem main.cpp Library.cpp Membership.cpp
// g++ -o LibraryManagementSystem main.cpp Library.cpp Membership.cpp

#include <iostream>
#include <cstdlib>
#include <limits>
#include "Library.hpp"
#include "Membership.hpp"
using namespace std;
using LibSys::Library;
using MemberSys::Membership;

int main(){

    Library library;
    Membership member;
    library.loadFile();
    member.loadFile();
    
    string input;    int choice;    bool proceed;
    do{
        input = "";     choice = 0;     proceed = false;
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
        cout << "\n\t13. Save data\n";
        
        cout << "\n\t0.  Exit System\n";

        cout << "\n\n\tInput : ";
        while(!(cin >> choice)){
            cout << "\n\tERROR! Please choose valid option provided ...\n";
            cout << "\n\tInput : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cin.clear();
        cin.ignore();
        system("cls");
        switch(choice){
            case 1:
                library.addBook();
                break;
            case 2:
                library.viewBookInfo();
                break;
            case 3:
                library.editBook();
                break;
            case 4:
                library.displayAllBook();
                break;
            case 5:
                library.deleteBook();
                break;
            case 6:
                member.addMember();
                break;
            case 7:
                member.displayAllMember();
                break;
            case 8:
                member.editMember();
                break;
            case 9:
                member.deleteMember();
                break;
            case 10:
                cout << "\n\tEnter Member ID : ";
                cin >> input;
                proceed = member.checkMembership(input);
                if(proceed){
                    library.borrowBook(input, member.getName(input));
                    member.updateTotalBookBorrow(input, "borrow");
                }
                break;
            case 11:
                input = library.returnBook();
                if(input != ""){
                    member.updateTotalBookBorrow(input, "return");
                }
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
                cout << "\n Exiting Library Management System ...\n\n";
                break;
            default:
                break;
        }

        if(choice != 0)
            cout << "\n Redirecting to main menu ..." << endl << endl;
        system("pause");
        
    }while(choice != 0);

    return 0;
}