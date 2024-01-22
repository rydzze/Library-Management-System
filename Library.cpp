#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <queue>
#include "Library.hpp"
using namespace std;
using namespace LibSys;

Library::Library() : head(NULL), totalBook(0){} 

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
    return id.str();
}

//for Sarvien - add some interfaces here for attractive looking lol
void Library::addBook(){
    string userInput;

    Book *newBook = new Book;
    cout << "\nTitle : ";
    getline(cin, userInput);
    newBook -> title = userInput;
    cout << "\nAuthor: ";
    getline(cin, userInput);
    newBook -> author = userInput;
    cout << "\nGenre : ";
    getline(cin, userInput);
    newBook -> genre = userInput;        
    newBook -> ID = generateBookID(userInput);
    cout << "\nYear  : ";
    getline(cin, userInput);
    newBook -> year = stoi(userInput);
    cout << "\nISBN  : ";
    getline(cin, userInput);
    newBook -> ISBN = stoll(userInput);
    cout << "\nPublisher  : ";
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

//add column to check book availability
void Library::displayAllBook(){
    if(isEmpty()){
        cout << "\nEmpty library ...\n";
        return;
    }

    if(!sorted){
        mergeSort(head);
        sorted = true;
    }

    Book* curr = head;
    cout << "+" << setfill('-') << setw(7) << "+" << setw(45) << "+" << setw(21) << "+" << setw(13) << "+" << endl;
    cout << "|" << setfill(' ') << setw(6) << left << "ID" << "|" << setw(44) << left << "Title" << "|"
                << setw(20) << left << "Author" << "|" << setw(12) << left << "Genre" << "|" << endl;

    while (curr != NULL){
        cout << "|" << setfill('-') << setw(7) << right << "|" << setw(45) << "|" << setw(21) << "|" << setw(13) << "|" << endl;
        cout << "|" << setfill(' ') << setw(6) << left << curr -> ID << "|" << setw(44) << left << curr -> title << "|"
                    << setw(20) << left << curr -> author << "|" << setw(12) << left << curr -> genre << "|" << endl;
        curr = curr -> next;
    } 
    cout << "+" << setfill('-') << setw(7) << right << "+" << setw(45) << "+" << setw(21) << "+" << setw(13) << "+" << endl;
}

void Library::viewBookInfo(){
    if(isEmpty()){
        return;
    }
    
    string userInput;
    cout << "\nEnter Book ID : ";
    cin >> userInput; 

    Book* curr = head;
    while(curr != NULL)
    {
        if(curr -> ID == userInput){
            cout << "+" << setfill('-') << setw(13) << "+" << setfill('-') << setw(47) << "+" << endl;
            cout << "|" << setfill(' ') << left << setw(12) << " Title" << "| " << setw(45) << curr->title << "|" << endl;
            cout << "|" << setfill(' ') << left << setw(12) << " Author" << "| " << setw(45) << curr->author << "|" << endl;
            cout << "|" << setfill(' ') << left << setw(12) << " Genre" << "| " << setw(45) << curr->genre << "|" << endl;
            cout << "|" << setfill(' ') << left << setw(12) << " Year" << "| " << setw(45) << curr->year << "|" << endl;
            cout << "|" << setfill(' ') << left << setw(12) << " ISBN" << "| " << setw(45) << curr->ISBN << "|" << endl;
            cout << "|" << setfill(' ') << left << setw(12) << " Publisher" << "| " << setw(45) << curr->publisher << "|" << endl;
            cout << "+" << setfill('-') << setw(13) << right << "+" << setfill('-') << setw(47) << "+" << endl;
            
            if(curr -> borrowStatus == true){
                cout << "\nBorrow Status : Borrowed\n" << endl;
                cout << "\nMember ID     : " << curr -> memberID << endl;
                cout << "\nMember Name   : " << curr -> memberName << endl;
            }
            else{
                cout << "\nBorrow Status : Available for borrow" << endl;
            }

            return;
        }
        curr = curr -> next;
    }
    if(curr == NULL){
        cout << "\nBook didn't exist in system ...\n";
    }
}

//for Sarvien - add some interfaces here for attractive looking lol
void Library::editBook(){
    if(isEmpty()){
        return;
    }
    
    string userInput;
    cout << "\nEnter Book ID : ";
    cin >> userInput;

    Book* curr = head;
    while(curr != NULL){
        if(curr -> ID == userInput){

            if(curr -> borrowStatus == true){
                cout << "\nBook was borrowed by someone ...";
                cout << "\nUnable to edit book info ...";
                return;
            }

            cout<<"\nEditing book with ID "<< curr -> ID << endl;

            cout << "\nTitle : ";
            getline(cin, userInput);
            curr -> title = userInput;
            cout << "\nAuthor: ";
            getline(cin, userInput);
            curr -> author = userInput;
            cout << "\nGenre : ";
            getline(cin, userInput);
            curr -> genre = userInput;
            cout << "\nYear  : ";
            getline(cin, userInput);
            curr -> year = stoi(userInput);
            cout << "\nISBN  : ";
            getline(cin, userInput);
            curr -> ISBN = stoll(userInput);
            cout << "\nPublisher  : ";
            getline(cin, userInput);
            curr -> publisher = userInput;

            cout << "\nBook with ID " << curr -> ID << " edited successfully ...\n";
            return;
        }
        curr = curr -> next;
    }
    cout << "\nBook didn't exist in system ...\n";
    return;
}  

void Library::deleteBook(){
    if (isEmpty()) {
        return;
    }

    string userInput;
    cout << "\nEnter Book ID : ";
    cin >> userInput;

    Book* curr = head;
    Book* prev = NULL;

    while (curr != NULL){
        if(curr -> ID == userInput){

            if(curr -> borrowStatus == true){
                cout << "\nBook was borrowed by someone ...";
                cout << "\nUnable to delete book from data ...";
                return;
            }

            if (prev == NULL){
                head = curr -> next;
            }
            else{
                prev -> next = curr -> next;
            }

            cout << "\nBook with ID " << userInput << " removed successfully ...\n";
            delete curr;
            totalBook--;
            return;
        }
        prev = curr;
        curr = curr -> next;
    }

    cout << "\nBook with ID " << userInput << " not found ...\n";
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
}

void Library::borrowBook(const string& ID, const string& name){
    if(isEmpty()){
        cout << "\nEmpty library ...\n";
        return;
    }

    string userInput;
    cout << "\nEnter Book ID : ";
    cin >> userInput;

    Book* curr = head;
    while(curr != NULL){
        if(curr -> ID == userInput){
            if(curr -> borrowStatus == true){
                cout << "\nThe book was borrowed by someone else ...\n";
                return;
            }
            
            curr -> borrowStatus = true;
            curr -> memberID = ID;
            curr -> memberName = name;
            cout << "\nBook with ID " << curr -> ID << " has been borrowed!\n";
            return;
        }
        curr = curr -> next;
    }
    cout << "\nBook didn't exist in system ...\n";
    return;
}

void Library::returnBook(){
    if(isEmpty()){
        cout << "\nEmpty library ...\n";
        return;
    }

    string userInput;
    cout << "\nEnter Book ID : ";
    cin >> userInput;

    Book* curr = head;
    while(curr != NULL){
        if(curr -> ID == userInput){
            if(curr -> borrowStatus == false){
                cout << "\nThe book is not borrowed ...\n";
                return;
            }

            curr -> borrowStatus = false;
            curr -> memberID = "";
            curr -> memberName = "";
            cout << "\nBook with ID " << curr -> ID << " have been returned!\n";
            return;
        }
        curr = curr -> next;
    }
    cout << "\nBook didn't exist in system ...\n";
    return;
}

void Library::loadFile(){
    ifstream readFile("bookData.txt");
    if(!readFile.is_open()){
        cout << "\nError: Unable to open file for reading." << endl;
        return;
    }

    queue<Book> Queue;
    string line;
    while(getline(readFile, line)){
        stringstream ss(line);
        string input;

        string ID, title, author, genre, publisher, memberID, memberName;
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

    cout << "\n Book data loaded successfully" << endl;
    readFile.close();
}

void Library::saveFile(){
    ofstream writeFile("bookData.txt");
    if(!writeFile.is_open()){
        cout << "\nError: Unable to open file for writing." << endl;
        return;
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

    cout << "\n Book data saved successfully" << endl;
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
    if(head == NULL || head -> next == NULL) {
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
    if (left == NULL)      return right;
    else if (right == NULL) return left;

    if (compareBookID(left -> ID, right -> ID) <= 0){
        left -> next = merge(left -> next, right);
        return left;
    } else {
        right -> next = merge(left, right -> next);
        return right;
    }
}

void Library::divideList(Book* head, Book*& firstList, Book*& secondList){
    Book* slow = head;
    Book* fast = head -> next;

    while (fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    firstList = head;
    secondList = slow -> next;
    slow -> next = NULL;
}