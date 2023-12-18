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
        Book* current = head;
        while(current -> next != NULL){
            current = current -> next;
        }
        current -> next = newBook;
    }

    totalBook++;
}

void Library::editBook(const int& ID, const string& title,
                      const string& author, const string& genre,
                      const int& year, const long long int& ISBN,
                      const string& publisher)
{                          
    int first = 1001;
    int last = 1000 + getTotalBook[];
    int ID = int value
    
    int binarySearch (int anArray[], int first, int last , int value)
{
    int index;
    if (first > last) index = -1;
    //There is no number in the array
    else{
        int mid = (first+last) /2;
    //find mid point
        if(value == anArray[mid] )
            index = mid;
        else if(value < anArray[mid])
            index = binarySearch(anArray, first, mid-1, value);
        else
            index = binarySearch(anArray, mid+1, last, value);
    }
    return index;
}
}

void Library::searchBook(const int& ID){

}

void Library::displayAllBook(){

}

void Library::deleteBook(const int& ID){

}
