#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <queue>
#include <limits>
#include "Library.hpp"
using namespace std;
using namespace LibSys;

Library::Library() : head(NULL), totalBook(0) {} 

Library::~Library(){
    Library::deleteAllBook();
}


bool Library::isEmpty(){
    return totalBook == 0;
}

int Library::getTotalBook(){
    return totalBook;
}

int Library::getBookIDCounter(){
    return bookIDCounter;
}

string Library::generateBookID(const string& genre){
    char headerID = genre[0];
    if(genre != "Science" && genre != "History" && genre != "Fantasy" && genre != "Comic" && genre != "Philosophy"){
        headerID = 'Z';
    }
    ostringstream id;
    id << headerID << setw(3) << setfill('0') << getBookIDCounter() + 1;

    Book* curr = head;
    while(curr != NULL){
        if(curr -> ID == id.str()){
            int newIDNum = stoi(id.str().substr(1)) + 1;
            id.str("");
            id << headerID << setw(3) << setfill('0') << newIDNum;        
        }
        curr = curr -> next;
    }
    return id.str();
}


void Library::addBook(){
    string userInput;
    cout << "\n\tAdding new book into the system ..." << endl;
    cout << "\t___________________________________" << endl;

    Book *newBook = new Book;
    try{
        cout << "\n\tTitle     : ";
        getline(cin, userInput);
        newBook -> title = userInput;
        cout << "\n\tAuthor    : ";
        getline(cin, userInput);
        newBook -> author = userInput;
        cout << "\n\tGenre     : ";
        getline(cin, userInput);
        newBook -> genre = userInput;        
        newBook -> ID = generateBookID(userInput);
        cout << "\n\tYear      : ";
        getline(cin, userInput);
        newBook -> year = stoi(userInput);
        cout << "\n\tISBN      : ";
        getline(cin, userInput);
        newBook -> ISBN = stoll(userInput);
        cout << "\n\tPublisher : ";
        getline(cin, userInput);
        newBook -> publisher = userInput;
        newBook -> borrowStatus = false;
        newBook -> memberID = "";
        newBook -> memberName = "";

        newBook -> next = NULL;

        if(isEmpty()){
            head = newBook;
        }
        else{
            Book* curr = head;
            while(curr -> next != NULL){
                curr = curr -> next;
            }
            curr -> next = newBook;
        }

        bookIDCounter++;
        totalBook++;
        sorted = false;

        cout << "\n\n\tNew book has been added into the system!";
        cout << "\n\tBook ID : " << newBook -> ID << endl << endl;
    }
    catch(const invalid_argument& e){
        cerr << "\n\n\n\t******************************************************";
        cerr << "\n\t ERROR! MAKE SURE YOU FOLLOW THE CORRECT INPUT FORMAT ";
        cerr << "\n\t******************************************************" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Library::addBook(const string& ID, const string& title, const string& author, const string& genre,
                      const int& year, const long long int& ISBN, const string& publisher,
                      const bool& borrowStatus, const string& memberID, const string& memberName)
{
    Book *newBook = new Book;
    newBook -> ID = ID;
    newBook -> title = title;
    newBook -> author = author;
    newBook -> genre = genre;
    newBook -> year = year;
    newBook -> ISBN = ISBN;
    newBook -> publisher = publisher;
    newBook -> borrowStatus = borrowStatus;
    newBook -> memberID = memberID;
    newBook -> memberName = memberName;
    newBook -> next = NULL;

    if(isEmpty()){
        head = newBook;
    }
    else{
        Book* curr = head;
        while(curr -> next != NULL){
            curr = curr -> next;
        }
        curr -> next = newBook;
    }

    bookIDCounter++;
    totalBook++;
}

void Library::viewBookInfo(){
    if(isEmpty()){
        cout << "\n\tNo book stored in the system :(" << endl << endl;
        return;
    }
    
    string userInput;
    cout << "\n\tViewing book's info stored in the system ..." << endl;
    cout << "\t____________________________________________" << endl;

    cout << "\n\tEnter Book ID : ";
    cin >> userInput;

    Book* curr = head;
    while(curr != NULL){
        if(curr -> ID == userInput){
            cout << "\n\t+" << setfill('-') << setw(13) << "+" << setfill('-') << setw(47) << "+" << endl;
            cout << "\t|" << setfill(' ') << left << setw(12) << " Title" << "| " << setw(45) << curr->title << "|" << endl;
            cout << "\t|" << setfill(' ') << left << setw(12) << " Author" << "| " << setw(45) << curr->author << "|" << endl;
            cout << "\t|" << setfill(' ') << left << setw(12) << " Genre" << "| " << setw(45) << curr->genre << "|" << endl;
            cout << "\t|" << setfill(' ') << left << setw(12) << " Year" << "| " << setw(45) << curr->year << "|" << endl;
            cout << "\t|" << setfill(' ') << left << setw(12) << " ISBN" << "| " << setw(45) << curr->ISBN << "|" << endl;
            cout << "\t|" << setfill(' ') << left << setw(12) << " Publisher" << "| " << setw(45) << curr->publisher << "|" << endl;
            cout << "\t+" << setfill('-') << setw(13) << right << "+" << setfill('-') << setw(47) << "+" << endl;
            
            if(curr -> borrowStatus == true){
                cout << "\n\tStatus      : Borrowed" << endl;
                cout << "\n\tMember ID   : " << curr -> memberID;
                cout << "\n\tMember Name : " << curr -> memberName << endl << endl;
            }
            else{
                cout << "\n\tStatus : Available for borrow" << endl << endl;
            }
            return;
        }
        curr = curr -> next;
    }
    if(curr == NULL){
        cout << "\n\tSorry, book with ID " << userInput << " did not exist in the system" << endl << endl;
    }
    return;
}

void Library::editBook(){
    if(isEmpty()){
        cout << "\n\tNo book stored in the system :(" << endl << endl;
        return;
    }
    
    string userInput;
    cout << "\n\tEditing book's info stored in the system ..." << endl;
    cout << "\t____________________________________________" << endl;

    cout << "\n\tEnter Book ID : ";
    cin >> userInput;

    Book* curr = head;
    try{
        while(curr != NULL){
            if(curr -> ID == userInput){
                if(curr -> borrowStatus){
                    cout << "\n\tThis book was borrowed by a member";
                    cout << "\n\tAbort editing process ..." << endl << endl;
                    return;
                }
                cout<<"\n\tEditing book's info with ID "<< curr -> ID << endl;
                
                cin.clear();
                cin.ignore();
                cout << "\n\tTitle     : ";
                getline(cin, userInput);
                curr -> title = userInput;
                cout << "\n\tAuthor    : ";
                getline(cin, userInput);
                curr -> author = userInput;
                cout << "\n\tGenre     : ";
                getline(cin, userInput);
                curr -> genre = userInput;
                cout << "\n\tYear      : ";
                getline(cin, userInput);
                curr -> year = stoi(userInput);
                cout << "\n\tISBN      : ";
                getline(cin, userInput);
                curr -> ISBN = stoll(userInput);
                cout << "\n\tPublisher : ";
                getline(cin, userInput);
                curr -> publisher = userInput;

                cout << "\n\n\tBook's info with ID " << curr -> ID << " has been edited successfully!" << endl << endl;
                return;
            }
            curr = curr -> next;
        }
        cout << "\n\tSorry, book with ID " << userInput << " did not exist in the system" << endl << endl;
        return;
    }
    catch(const invalid_argument& e){
        cerr << "\n\n\n\t******************************************************";
        cerr << "\n\t ERROR! MAKE SURE YOU FOLLOW THE CORRECT INPUT FORMAT ";
        cerr << "\n\t******************************************************" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}  

void Library::displayAllBook(){
    if(isEmpty()){
        cout << "\n\tNo book stored in the system :(" << endl << endl;
        return;
    }
    if(!sorted){
        mergeSort(head);
        sorted = true;
    }

    cout << "\n\tViewing all books stored in the system ..." << endl;
    cout << "\t__________________________________________" << endl << endl;

    string borrowed = ""; 
    Book* curr = head;
    cout << "+" << setfill('-') << setw(7) << "+" << setw(45) << "+" << setw(21) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
    cout << "|" << setfill(' ') << setw(6) << left << "ID" << "|" << setw(44) << left << "Title" << "|"
                << setw(20) << left << "Author" << "|" << setw(12) << left << "Genre" << "|"
                << setw(11) << left << "Borrowed?" << "|" << endl;
    while (curr != NULL){
        if(curr -> borrowStatus == true)    borrowed = "     X";
        else                                borrowed = "";

        cout << "|" << setfill('-') << setw(7) << right << "|" << setw(45) << "|" << setw(21) << "|" << setw(13) << "|" << setw(12) << "|" << endl;
        cout << "|" << setfill(' ') << setw(6) << left << curr -> ID << "|" << setw(44) << left << curr -> title << "|"
                    << setw(20) << left << curr -> author << "|" << setw(12) << left << curr -> genre << "|"
                    << setw(11) << left << borrowed << "|" << endl;
        curr = curr -> next;
    } 
    cout << "+" << setfill('-') << setw(7) << right << "+" << setw(45) << "+" << setw(21) << "+" << setw(13) << "+" << setw(12) << "+" << endl;
}

void Library::deleteBook(){
    if (isEmpty()) {
        cout << "\n\tNo book stored in the system :(" << endl << endl;
        return;
    }

    string userInput;
    cout << "\n\tDeleting book stored in the system ..." << endl;
    cout << "\t______________________________________" << endl;

    cout << "\n\tEnter Book ID : ";
    cin >> userInput;

    Book* curr = head;
    Book* prev = NULL;
    while (curr != NULL){
        if(curr -> ID == userInput){
            if(curr -> borrowStatus){
                cout << "\n\tThis book was borrowed by a member";
                cout << "\n\tAbort deletion process ..." << endl << endl;
                return;
            }

            if (prev == NULL){
                head = curr -> next;
            }
            else{
                prev -> next = curr -> next;
            }

            cout << "\n\n\tThe book has been deleted successfully!" << endl << endl;
            delete curr;
            totalBook--;
            return;
        }
        prev = curr;
        curr = curr -> next;
    }
    cout << "\n\tSorry, book with ID " << userInput << " did not exist in the system" << endl << endl;
    return;
}

void Library::deleteAllBook(){
    if(isEmpty()){
        return;
    }

    Book* curr = head;
    Book* nextBook;
    while(curr != NULL){
        nextBook = curr -> next;
        delete curr;
        curr = nextBook;
    }

    head = NULL;
    totalBook = 0;
    bookIDCounter = 0;
}


void Library::borrowBook(const string& ID, const string& name){
    if(isEmpty()){
        cout << "\n\tNo book stored in the system :(" << endl << endl;
        return;
    }

    string userInput;
    cout << "\n\tBorrowing book from the library ..." << endl;
    cout << "\t___________________________________" << endl;

    cout << "\n\tEnter Book ID : ";
    cin >> userInput;

    Book* curr = head;
    while(curr != NULL){
        if(curr -> ID == userInput){
            if(curr -> borrowStatus == true){
                cout << "\n\tSorry, this book was borrowed by another member";
                cout << "\n\tAbort borrowing process ..." << endl << endl;
                return;
            }
            curr -> borrowStatus = true;
            curr -> memberID = ID;
            curr -> memberName = name;
            cout << "\n\tBook with ID " << curr -> ID << " has been borrowed by the member!";
            cout << "\n\n\tMember's Info";
            cout << "\n\tID   : " << ID;
            cout << "\n\tName : " << name << endl << endl;
            return;
        }
        curr = curr -> next;
    }
    cout << "\n\tSorry, book with ID " << userInput << " did not exist in the system" << endl << endl;
    return;
}

string Library::returnBook(){
    if(isEmpty()){
        cout << "\n\tNo book stored in the system :(" << endl << endl;
        return "";
    }

    string userInput, temp;
    cout << "\n\tReturning book to the library ..." << endl;
    cout << "\t_________________________________" << endl;

    cout << "\n\tEnter Book ID : ";
    cin >> userInput;

    Book* curr = head;
    while(curr != NULL){
        if(curr -> ID == userInput){
            if(curr -> borrowStatus == false){
                cout << "\n\tThe book is not borrowed by any member";
                cout << "\n\tAbort returning process ..." << endl << endl;
                return "";
            }

            curr -> borrowStatus = false;
            temp = curr -> memberID;
            curr -> memberID = "";
            curr -> memberName = "";
            cout << "\n\tBook with ID " << curr -> ID << " has been returned!" << endl << endl;
            return temp;
        }
        curr = curr -> next;
    }
    cout << "\n\tSorry, book with ID " << userInput << " did not exist in the system" << endl << endl;
    return "";
}


void Library::loadFile(){
    ifstream readFile("bookData.txt");
    if(!readFile.is_open()){
        cerr << "\n ERROR! Missing bookData.txt file in the directory ...";
        return;
    }

    queue<Book> Queue;
    string line;
    try{
        while(getline(readFile, line)){
            stringstream ss(line);
            string input, ID, title, author, genre, publisher, memberID, memberName;
            int year;
            long long int ISBN;
            bool borrowStatus;

            getline(ss, ID, '~');
            getline(ss, title, '~');
            getline(ss, author, '~');
            getline(ss, genre, '~');
            getline(ss, input, '~');
            year = stoi(input);
            getline(ss, input, '~');
            ISBN = stoll(input);
            getline(ss, publisher, '~');
            getline(ss, input, '~');
            borrowStatus = (input == "1" ? true : false); //terniary operator if-else
            getline(ss, memberID, '~');
            getline(ss, memberName, '~');

            Book temp{ID, title, author, genre, publisher, year, ISBN, borrowStatus, memberID, memberName, NULL};
            Queue.push(temp);
        }

        while (!Queue.empty()){
            Book curr = Queue.front();
            Queue.pop();

            addBook(curr.ID, curr.title, curr.author, curr.genre, curr.year, curr.ISBN,
                    curr.publisher, curr.borrowStatus, curr.memberID, curr.memberName);
        }

        cout << "\n Book data loaded successfully!";
    }
    catch(const invalid_argument& e){
        cerr << "\n\n\n\t**************************************************************";
        cerr << "\n\t ERROR! BAD FILE READING, THE DATA MIGHT HAVE BEEN CORRUPTED.";
        cerr << "\n\t**************************************************************" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        deleteAllBook();
    }
    readFile.close();
}

void Library::saveFile(){
    ofstream writeFile("bookData.txt");
    if(!writeFile.is_open()){
        cerr << "\n ERROR! Missing bookData.txt file in the directory ...";
        return;
    }
    if(!sorted){
        mergeSort(head);
        sorted = true;
    }
    
    Book* curr = head;
    while(curr != NULL){
        writeFile << curr -> ID << '~' << curr -> title << '~'
                  << curr -> author << '~' << curr -> genre << '~'
                  << curr -> year << '~' << curr -> ISBN << '~'
                  << curr -> publisher << '~' << curr -> borrowStatus << '~'
                  << curr -> memberID << '~' << curr -> memberName << '~' << endl;
        curr = curr -> next;
    }

    if(writeFile.good()){
        cout << "\n Book data saved successfully!";
    }
    else{
        cerr << "\n ERROR! There might be missing book data during saving process ...";
    }
    writeFile.close();
}


int Library::compareBookID(const string& ID1, const string& ID2) {
    char genreB1 = ID1[0];
    char genreB2 = ID2[0];

    if (genreB1 != genreB2) {
        return genreB1 - genreB2;
    }

    int num1 = stoi(ID1.substr(1));
    int num2 = stoi(ID2.substr(1));

    return num1 - num2;
}

void Library::mergeSort(Book*& head){
    if(head == NULL || head -> next == NULL){
        return;
    }
    Book* left;
    Book* right;

    divideList(head, left, right);
    mergeSort(left);
    mergeSort(right);

    head = merge(left, right);
}

Library::Book* Library::merge(Book* left, Book* right){
    if(left == NULL)       return right;
    else if(right == NULL) return left;

    if(compareBookID(left -> ID, right -> ID) <= 0){
        left -> next = merge(left -> next, right);
        return left;
    }
    else{
        right -> next = merge(left, right -> next);
        return right;
    }
}

void Library::divideList(Book* head, Book*& firstList, Book*& secondList){
    Book* slow = head;
    Book* fast = head -> next;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    firstList = head;
    secondList = slow -> next;
    slow -> next = NULL;
}