#include <iostream>
#include <cstdlib>
#include "LibrarySys.hpp"
using namespace std;
using System::Library;

void init(Library& library);

int main(){

    Library library;
    init(library);
    
    string id, title, author, genre, publisher;
    int year;
    long long int ISBN;
    
    int choice = 0;
    do{
        system("cls");
        cout << "\n **************************************************************************\n\n";
        cout << "                      WELCOME TO LIBRARY MANAGEMENT SYSTEM                   \n";
        cout << "                                   MAIN MENU                                 \n";
        cout << "\n **************************************************************************\n\n";
        cout << "\n\t1. Add new book";
        cout << "\n\t2. Edit book details";
        cout << "\n\t3. Search book info";
        cout << "\n\t4. Display all book";
        cout << "\n\t5. Delete existing book";
        cout << "\n\t6. Load data from file";
        cout << "\n\t7. Save data into file";
        
        cout << "\n\n\t0. Exit System";

        cout << "\n\n\tInput: ";
        cin >> choice;
        cin.ignore();

        system("cls");
        switch(choice){
            case 1:
                library.addBook();
                break;
            
            case 2:
                library.displayAllBook();
                
                library.editBook();
                break;
            case 3:
                cout << "\nEnter Book ID: ";
                cin >> id;
                library.searchBookInfo(id);
                break;
            case 4:
                library.MergeSort();
                library.displayAllBook();
                break;
            case 5:
                library.displayAllBook();
                library.deleteBook();
                break;
            case 6:
                library.deleteAllBook();
                library.loadFile();
                break;
            case 7:
                library.saveFile();
                break;
            case 0:
                cout << "\nExit ...\n";
                break;
            default:
                break;
        }
        system("pause");
        
    }while(choice != 0);

    return 0;
}

void init(Library& library){
    library.loadFile();

    // library.addBook("S001", "A Brief History of Time", "Stephen Hawking", "Science", 1988, 9780553380163, "Bantam Books");
    // library.addBook("S002", "The Selfish Gene", "Richard Dawkins", "Science", 1976, 9780192860927, "Oxford University Press");
    // library.addBook("S003", "Cosmos", "Carl Sagan", "Science", 1980, 9780345539434, "Random House");
    // library.addBook("S004", "The Elegant Universe", "Brian Greene", "Science", 1999, 9780375708114, "Vintage Books");
    // library.addBook("S005", "The Double Helix", "James D. Watson", "Science", 1968, 9780743216302, "Touchstone");

    // library.addBook("H006", "Sapiens: A Brief History of Humankind", "Yuval Noah Harari", "History", 2014, 9780062316097, "Harper");
    // library.addBook("H007", "A People's History of the United States", "Howard Zinn", "History", 1980, 9780061965586, "Harper Perennial");
    // library.addBook("H008", "The Guns of August", "Barbara W. Tuchman", "History", 1962, 9780345476098, "Presidio Press");
    // library.addBook("H009", "The Wright Brothers", "David McCullough", "History", 2015, 9781476728759, "Simon & Schuster");
    // library.addBook("H010", "The History of England", "Peter Ackroyd", "History", 2011, 9780312674928, "St. Martin's Press");

    // library.addBook("F011", "The Hobbit", "J.R.R. Tolkien", "Fantasy", 1937, 9780618260300, "Mariner Books");
    // library.addBook("F012", "Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "Fantasy", 1997, 9780590353427, "Scholastic");
    // library.addBook("F013", "The Name of the Wind", "Patrick Rothfuss", "Fantasy", 2007, 9780756404741, "DAW Books");
    // library.addBook("F014", "A Game of Thrones", "George R.R. Martin", "Fantasy", 1996, 9780553103540, "Bantam Spectra");
    // library.addBook("F015", "Mistborn: The Final Empire", "Brandon Sanderson", "Fantasy", 2006, 9780765311788, "Tor Books");

    // library.addBook("C016", "Watchmen", "Alan Moore", "Comic", 1987, 9780930289232, "DC Comics");
    // library.addBook("C017", "Batman: The Killing Joke", "Alan Moore", "Comic", 1988, 9780930289454, "DC Comics");
    // library.addBook("C018", "Maus", "Art Spiegelman", "Comic", 1986, 9780394747231, "Pantheon Books");
    // library.addBook("C019", "Spider-Man: The Night Gwen Stacy Died", "Gerry Conway", "Comic", 1973, 9780785167179, "Marvel Comics");
    // library.addBook("C020", "Persepolis", "Marjane Satrapi", "Comic", 2000, 9780375714573, "Pantheon Books");

    // library.addBook("P021", "Sophie's World", "Jostein Gaarder", "Philosophy", 1991, 9780374500016, "Farrar, Straus and Giroux");
    // library.addBook("P022", "Being and Time", "Martin Heidegger", "Philosophy", 1927, 9780061575594, "Harper Perennial Modern Thought");
    // library.addBook("P023", "Thus Spoke Zarathustra", "Friedrich Nietzsche", "Philosophy", 1883, 9780140441185, "Penguin Classics");
    // library.addBook("P024", "A Theory of Justice", "John Rawls", "Philosophy", 1971, 9780674880162, "Belknap Press");
    // library.addBook("P025", "Being and Nothingness", "Jean-Paul Sartre", "Philosophy", 1943, 9780671867805, "Washington Square Press");
}
