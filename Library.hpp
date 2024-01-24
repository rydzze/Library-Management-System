#include <cstdlib>
using namespace std;
#ifndef LIBRARY_HPP
#define LIBRARY_HPP

namespace LibSys{

class Library{
    private:
        struct Book{
            string ID, title, author, genre, publisher;
            int year;
            long long int ISBN;
            bool borrowStatus;
            string memberID, memberName;
            Book* next;
        };

        int totalBook = 0, bookIDCounter = 0;
        bool sorted = true;
        Book* head;
        
    public:
        Library();
        ~Library();

        bool isEmpty(); 
        int getTotalBook();
        int getBookIDCounter();
        string generateBookID(const string& genre);

        void addBook();
        void addBook(const string& ID, const string& title, const string& author, const string& genre,
                     const int& year, const long long int& ISBN, const string& publisher,
                     const bool& borrowStatus, const string& memberID, const string& memberName);
        void viewBookInfo();
        void editBook();
        void displayAllBook();
        void deleteBook();
        void deleteAllBook();

        void borrowBook(const string& ID, const string& name);
        string returnBook();

        void loadFile();
        void saveFile();
        
        int compareBookID(const string& id1, const string& id2);
        void mergeSort(Book*& headList);
        Book* merge(Book* book1, Book* book2);
        void divideList(Book* head, Book*& firstList, Book*& secondList);
};

};

#endif