#include <cstdlib>
using namespace std;
#ifndef LIBRARY_SYS_HPP
#define LIBRARY_SYS_HPP

namespace System{

class Library{
    private:
        struct Book{
            int ID;
            string title;
            string author;
            string genre;
            int year;
            int ISBN;
            string publisher;
            Book* next;
        };

        Book *front;
        
    public:

        Library();
        ~Library();

        bool isEmpty();
        int getTotalBook();

        void addBook(const Book& book);
        void editBook(const int& ID);
        void searchBook(const int& ID);
        void displayAllBook();
        void deleteBook(const int& ID);
};

};

#endif