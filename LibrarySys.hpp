#include <cstdlib>
using namespace std;
#ifndef LIBRARY_SYS_HPP
#define LIBRARY_SYS_HPP

namespace System{

class Library{
    private:
        struct Book{
            string ID;
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

        void addBook(const string& ID, const string& title, const string& author,
                     const string& genre, const int& year, const long long int& ISBN,
                     const string& publisher);
        void editBook(const string& ID, const string& title, const string& author,
                      const string& genre, const int& year, const long long int& ISBN,
                      const string& publisher);
        void searchBookInfo(const string& ID);
        void displayAllBook();
        void deleteBook(const string& ID);
        void deleteAllBook();

        void loadFile();
        void saveFile();

        int compareBookID(const string& id1, const string& id2);
        void MergeSort();
        void MergeSort(Book** headRef);
        Book* SortedMerge(Book* a, Book* b);
        void FrontBackSplit(Book* source, Book** frontRef, Book** backRef);
};

};

#endif