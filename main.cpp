#include <iostream>
#include <cstdlib>
#include "LibrarySys.hpp"
using namespace std;
using System::Library;

void init();

int main(){

    init();
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

        switch(choice){
            case 1:
                //add
                break;
            case 2:
                //edit
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
        }

    }while(choice != 0);

    system("pause");
    return 0;
}

void init(){
    Library library;
    // library.addBook();
}