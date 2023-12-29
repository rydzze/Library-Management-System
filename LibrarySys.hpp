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
            long long int ISBN;
            string publisher;
            Book* next;
        };

        int totalBook;
        Book* head;
        
    public:

        Library();
        ~Library();

        bool isEmpty();
        int getTotalBook();

        void addBook(const int& ID, const string& title, const string& author,
                     const string& genre, const int& year, const long long int& ISBN,
                     const string& publisher);
        void editBook(const int& ID, const string& title, const string& author,
                      const string& genre, const int& year, const long long int& ISBN,
                      const string& publisher);
        void searchBookInfo(const int& ID);
        void displayAllBook();
        void deleteBook(const int& ID);
        void deleteAllBook();

        void loadFile();
        void saveFile();
};

};

#endif