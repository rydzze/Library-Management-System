#include <iostream>
#include <cstdlib>
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

void Library::addBook(const int& ID, const string& title,
                      const string& author, const string& genre,
                      const int& year, const long long int& ISBN,
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
        Book* current = head;
        while(current -> next != NULL){
            current = current -> next;
        }
        current -> next = newBook;
    }

    totalBook++;
}

void Library::editBook(const int& ID){

}

void Library::searchBook(const int& ID){

}

void Library::displayAllBook(){

}

void Library::deleteBook(const int& ID){

}
