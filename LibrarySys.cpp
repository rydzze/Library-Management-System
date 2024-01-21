#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <queue>
#include "LibrarySys.hpp"
using namespace std;
using namespace System;

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

string Library::generateBookID(const string& genre, int n){
    char headerID = genre[0];
    
    if(genre != "Science" && genre != "History" && genre != "Fantasy" && genre != "Comic" && genre != "Philosophy"){
        headerID = 'Z';
    }

    ostringstream id;
    id << headerID << setw(3) << setfill('0') << n + 1;
    return id.str();
}

//for Sarvien - add some interfaces here for attractive looking lol
void Library::addBook()
{
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
    newBook -> ID = generateBookID(userInput, getBookIDCounter());
    cout << "\nYear  : ";
    getline(cin, userInput);
    newBook -> year = stoi(userInput);
    cout << "\nISBN  : ";
    getline(cin, userInput);
    newBook -> ISBN = stoll(userInput);
    cout << "\nPublisher  : ";
    getline(cin, userInput);
    newBook -> publisher = userInput;

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

void Library::addBook(const string& ID, const string& title, const string& author,
                      const string& genre, const int& year, const long long int& ISBN,
                      const string& publisher)
{
    Book *newBook = new Book;
    newBook -> ID = ID;
    newBook -> title = title;
    newBook -> author = author;
    newBook -> genre = genre;
    newBook -> year = year;
    newBook -> ISBN = ISBN;
    newBook -> publisher = publisher;
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

//for Sarvien - add some interfaces here for attractive looking lol
void Library::editBook()
{
    string userInput;

    cout << "\nEnter Book ID: ";
    cin >> userInput;

    Book* curr = head;
    while(curr != NULL){
        if(curr -> ID == userInput){
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
            curr -> ID = generateBookID(userInput, getBookIDCounter());
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

void Library::viewBookInfo(){
    string userInput;
    cout << "\nEnter Book ID: ";
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
            return;
        }
        curr = curr -> next;
    }
    if(curr == NULL){
        cout << "\nBook didn't exist in system ...\n";
    }
}

void Library::displayAllBook(){
    if(isEmpty()){
        cout << "\nEmpty library ...\n";
        return;
    }
    
    MergeSort(&head);

    Book* current = head;
    cout << "+" << setfill('-') << setw(7) << "+" << setw(45) << "+" << setw(21) << "+" << setw(13) << "+" << endl;
    cout << "|" << setfill(' ') << setw(6) << left << "ID" << "|" << setw(44) << left << "Title" << "|"
                << setw(20) << left << "Author" << "|" << setw(12) << left << "Genre" << "|" << endl;

    while (current != NULL) {
        cout << "|" << setfill('-') << setw(7) << right << "|" << setw(45) << "|" << setw(21) << "|" << setw(13) << "|" << endl;
        cout << "|" << setfill(' ') << setw(6) << left << current->ID << "|" << setw(44) << left << current->title << "|"
                    << setw(20) << left << current->author << "|" << setw(12) << left << current->genre << "|" << endl;
        current = current -> next;
    } 
    cout << "+" << setfill('-') << setw(7) << right << "+" << setw(45) << "+" << setw(21) << "+" << setw(13) << "+" << endl;
}

void Library::deleteBook() {
    if (isEmpty()) {
        cout << "\nEmpty library ...\n";
        return;
    }

    string userInput;
    cout << "\nEnter Book ID: ";
    cin >> userInput;

    Book* curr = head;
    Book* prev = NULL;

    while (curr != NULL){
        if(curr -> ID == userInput){
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
        curr = curr->next;
    }

    cout << "\nBook with ID " << userInput << " not found ...\n";
}

void Library::deleteAllBook(){
    if(isEmpty()){
        return;
    }

    Book* current = head;
    Book* nextBook;
    while(current != NULL){
        nextBook = current -> next;
        delete current;
        current = nextBook;
    }
    head = NULL;
    totalBook = 0;
}

void Library::loadFile(){
    ifstream readFile("data.txt");
    if(!readFile.is_open()){
        cout << "\nError: Unable to open file for reading." << endl;
        return;
    }

    queue<Book> Queue;
    string line;
    while(getline(readFile, line)){
        stringstream ss(line);
        string token;

        string ID, title, author, genre, publisher;
        int year;
        long long int ISBN;

        getline(ss, ID, '~');
        getline(ss, title, '~');
        getline(ss, author, '~');
        getline(ss, genre, '~');
        getline(ss, token, '~');
        year = stoi(token);
        getline(ss, token, '~');
        ISBN = stoll(token);
        getline(ss, publisher, '~');

        Book tempBook{ID, title, author, genre, publisher, year, ISBN, NULL};
        Queue.push(tempBook);
    }

    while (!Queue.empty()) {
        Book current = Queue.front();
        Queue.pop();

        addBook(current.ID, current.title, current.author,
                current.genre, current.year, current.ISBN,
                current.publisher);
    }
    cout << "\n File loaded successfully" << endl;
    readFile.close();
}

void Library::saveFile(){
    ofstream writeFile("data.txt");
    if(!writeFile.is_open()){
        cout << "\nError: Unable to open file for writing." << endl;
        return;
    }
    
    Book* current = head;
    while(current != NULL){
        writeFile << current -> ID << '~' << current -> title << '~'
                  << current -> author << '~' << current -> genre << '~'
                  << current -> year << '~' << current -> ISBN << '~'
                  << current -> publisher << '~' << endl;
        current = current -> next;
    }
    cout << "\n File saved successfully" << endl;
    writeFile.close();
}



//for Ariff - SIMPLIFY THE CODE BELOW !!!

int Library::compareBookID(const string& id1, const string& id2) {
    char letter1 = id1[0];
    char letter2 = id2[0];

    if (letter1 != letter2) {
        return letter1 - letter2;
    }

    // If the first characters are the same, compare the numeric parts
    int num1 = stoi(id1.substr(1));
    int num2 = stoi(id2.substr(1));

    return num1 - num2;
}

void Library::MergeSort(Book** headRef) {
    Book* head = *headRef;
    Book* a;
    Book* b;

    if (head == NULL || head -> next == NULL) {
        return;
    }

    FrontBackSplit(head, &a, &b);

    MergeSort(&a);
    MergeSort(&b);

    *headRef = SortedMerge(a, b);
}

Library::Book* Library::SortedMerge(Book* a, Book* b) {
    Book* result = NULL;

    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    if (compareBookID(a->ID, b->ID) <= 0) {
        result = a;
        result -> next = SortedMerge(a -> next, b);
    } else {
        result = b;
        result -> next = SortedMerge(a, b -> next);
    }
    return result;
}

void Library::FrontBackSplit(Book* source, Book** frontRef, Book** backRef) {
    Book* fast;
    Book* slow;
    slow = source;
    fast = source -> next;

    while (fast != NULL) {
        fast = fast -> next;
        if (fast != NULL) {
            slow = slow -> next;
            fast = fast -> next;
        }
    }

    *frontRef = source;
    *backRef = slow -> next;
    slow -> next = NULL;
}
