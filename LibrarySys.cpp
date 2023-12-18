#include <iostream>
#include <cstdlib>
#include <iomanip>
#include "LibrarySys.hpp"
using namespace std;
using namespace System;

Library::Library() : head(NULL), totalBook(0) {} 

Library::~Library(){
    //delete all
}

bool Library::isEmpty(){
    return totalBook == 0;
}

int Library::getTotalBook(){
    return totalBook;
}
//create new var for ID creation
void Library::addBook(const int& ID, const string& title, const string& author,
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

    totalBook++;
}

//if not exist, no need to prompt
void Library::editBook(const int& ID, const string& title, const string& author,
                       const string& genre, const int& year, const long long int& ISBN,
                       const string& publisher)
{                    
    Book* curr = head;
    while(curr != NULL)
    {
        if(curr -> ID == ID){
           curr -> title = title;
           curr -> author = author;
           curr -> genre = genre;
           curr -> year = year;
           curr -> ISBN = ISBN;
           curr -> publisher = publisher;
           cout << "\nBook with ID " << ID << " edited successfully ...\n";
           return;
        }
        curr = curr -> next;
    }
    if(curr == NULL){
        cout << "\nBook didn't exist in system ...\n";
    }
}  

void Library::searchBookInfo(const int& ID){
    Book* curr = head;
    while(curr != NULL)
    {
        if(curr -> ID == ID){
           cout << "\nTitle :" << curr -> title;
           cout << "\nAuthor:" << curr -> author;
           cout << "\nGenre :" << curr -> genre;
           cout << "\nYear  :" << curr -> year;
           cout << "\nISBN  :" << curr -> ISBN;
           cout << "\nPublisher:" << curr -> publisher;
           return;
        }
        curr = curr -> next;
    }
    if(curr == NULL){
        cout << "\nBook didn't exist in system ...\n";
    }
}

//implement queue to seperate later, maybe ...
void Library::displayAllBook(){
    if(isEmpty()){
        cout << "\nEmpty library ...\n";
        return;
    }
    
    Book* current = head;
    cout << "+" << setfill('-') << setw(7) << "+" << setw(45) << "+" << setw(21) << "+" << setw(13) << "+" << endl;
    cout << "|" << setfill(' ') << setw(6) << left << "ID" << "|" << setw(44) << left << "Title" << "|"
                << setw(20) << left << "Author" << "|" << setw(12) << left << "Genre" << "|" << endl;

    while (current != NULL) {
        cout << "|" << setfill('-') << setw(7) << right << "+" << setw(45) << "+" << setw(21) << "+" << setw(13) << "|" << endl;
        cout << "|" << setfill(' ') << setw(6) << left << current->ID << "|" << setw(44) << left << current->title << "|"
                    << setw(20) << left << current->author << "|" << setw(12) << left << current->genre << "|" << endl;
        current = current -> next;
    } 
    cout << "+" << setfill('-') << setw(7) << right << "+" << setw(45) << "+" << setw(21) << "+" << setw(13) << "+" << endl;
}

//if not exist, no need to prompt
void Library::deleteBook(const int& ID){
    if(isEmpty()){
        return;
    }
    
    Book* curr = head;
    Book* prev = NULL;
    if(curr != NULL && curr -> ID == ID){
        head = curr -> next;
        delete curr;
        totalBook--;
        cout << "\nBook with ID " << ID << " removed successfully ...\n";
        return; 
    }
    while(curr != NULL && curr -> ID != ID){// 
        prev = curr;
        curr = curr -> next;
    }
    if(curr == NULL){
        cout << "\nBook didn't exist in system ...\n";
        return;
    }
    
    prev -> next = curr -> next;
    curr -> next = NULL;
    delete curr;
    cout << "\nBook with ID " << ID << " removed successfully ...\n";
    totalBook--;
}