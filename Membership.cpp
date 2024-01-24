#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <queue>
#include "Membership.hpp"
using namespace std;
using namespace MemberSys;

Membership::Membership() : head(NULL), totalMember(0), memberIDCounter(0){}

Membership::~Membership(){
    Membership::deleteAllMember();
}

bool Membership::isEmpty(){
    return totalMember == 0;
}

int Membership::getTotalMember(){
    return totalMember;
}

int Membership::getMemberIDCounter(){
    return memberIDCounter;
}

string Membership::generateMemberID(){
    ostringstream id;
    id << 'U' << setw(3) << setfill('0') << getMemberIDCounter() + 1;
    return id.str();
}

bool Membership::checkMembership(const string& ID){
    Member* curr = head;

    while(curr != NULL){
        if(curr -> ID == ID){
            return true;
        }
        curr = curr -> next;
    }
    cout << "\n\tMember with ID " << ID << " did not exist in the system";
    cout << "\n\tMake sure to register before borrowing a book" << endl << endl;
    return false;
}

string Membership::getName(const string& ID){
    Member* curr = head;

    while(curr != NULL){
        if(curr -> ID == ID){
            return curr -> name;
        }
        curr = curr -> next;
    }
    return "";
}

void Membership::updateTotalBookBorrow(const string& ID, const string& status){
    Member* curr = head;

    while(curr != NULL){
        if(curr -> ID == ID){
            if(status == "borrow")      curr -> totalBookBorrow++;
            else if(status == "return") curr -> totalBookBorrow--;

            return;
        }
        curr = curr -> next;
    }
    return;
}

void Membership::addMember(){
    string userInput;

    cout << "\n\tNEW MEMBER REGISTRATION :D !!!" << endl;
    cout << "\t______________________________" << endl;
    cout << "\n\n\tPlease fill in your details :)" << endl;

    Member* newMember = new Member;
    cout << "\n\tFull Name     : ";
    getline(cin, userInput);
    newMember -> name = userInput;
    cout << "\n\tPhone Number  : ";
    getline(cin, userInput);
    newMember -> phoneNum = userInput;
    cout << "\n\tEmail Address : ";
    getline(cin, userInput);
    newMember -> email = userInput;
    newMember -> ID = generateMemberID();
    newMember -> totalBookBorrow = 0;

    newMember -> next = NULL;

    if(isEmpty()){
        head = newMember;
    }
    else{
        Member* curr = head;
        while(curr -> next != NULL){
            curr = curr -> next;
        }
        curr -> next = newMember;
    }

    memberIDCounter++;
    totalMember++;

    cout << "\n\n\tWelcome, " << newMember -> name << "! Your member ID is " << newMember -> ID << endl << endl;
}

void Membership::addMember(const string& ID, const string& name, const string& phoneNum,
                           const string& email, const int& totalBookBorrow)
{
    Member* newMember = new Member;
    newMember -> ID = ID;
    newMember -> name = name;
    newMember -> phoneNum = phoneNum;
    newMember -> email = email;
    newMember -> totalBookBorrow = totalBookBorrow;
    newMember -> next = NULL;

    if(isEmpty()){
        head = newMember;
    }
    else{
        Member* curr = head;
        while(curr -> next != NULL){
            curr = curr -> next;
        }
        curr -> next = newMember;
    }

    memberIDCounter++;
    totalMember++;
}

void Membership::displayAllMember(){
    if(isEmpty()){
        cout << "\n\tNo member registered in the system :(" << endl << endl;
        return;
    }

    Member* curr = head;
    cout << "+" << setfill('-') << setw(7) << "+" << setw(20) << "+" << setw(20) << "+" << setw(35) << "+" << endl;
    cout << "|" << setfill(' ') << setw(6) << left << "ID" << "|" << setw(19) << left << "Name" << "|"
         << setw(19) << left << "Phone Number" << "|" << setw(34) << left << "Email Address" << "|" << endl;

    while(curr != NULL){
        cout << "|" << setfill('-') << setw(7) << right << "|" << setw(20) << "|" << setw(20) << "|" << setw(35) << "|" << endl;
        cout << "|" << setfill(' ') << setw(6) << left << curr -> ID << "|" << setw(19) << left << curr -> name << "|"
                    << setw(19) << left << curr -> phoneNum << "|" << setw(34) << left << curr -> email << "|"  << endl;
        curr = curr -> next;
    }
    cout << "+" << setfill('-') << setw(7) << right << "+" << setw(20) << "+" << setw(20) << "+" << setw(35) << "+" << endl;
}

void Membership::editMember(){
    if(isEmpty()){
        cout << "\n\tNo member registered in the system :(" << endl << endl;
        return;
    }
    
    string userInput;

    cout << "\n\tEditing member's info stored in the system ..." << endl;
    cout << "\t______________________________________________" << endl;

    cout << "\n\tEnter Member ID : ";
    cin >> userInput;

    Member* curr = head;
    while(curr != NULL){
        if(curr -> ID == userInput){

            if(curr -> totalBookBorrow != 0){
                cout << "\n\tThis member borrowed a book currently";
                cout << "\n\tAbort editing process ..." << endl << endl;
                return;
            }

            cout<<"\n\tEditing member's info with ID "<< curr -> ID << endl;

            cin.ignore();
            cout << "\n\tFull Name     : ";
            getline(cin, userInput);
            curr -> name = userInput;
            cout << "\n\tPhone Number  : ";
            getline(cin, userInput);
            curr -> phoneNum = userInput;
            cout << "\n\tEmail Address : ";
            getline(cin, userInput);
            curr -> email = userInput;

            cout << "\n\tMember's info with ID " << curr -> ID << " has been edited successfully!" << endl << endl;
            return;
        }
        curr = curr -> next;
    }
    cout << "\n\tSorry, member with ID " << userInput << " did not exist in the system" << endl << endl;
    return;
}

void Membership::deleteMember(){
    if(isEmpty()){
        cout << "\n\tNo member registered in the system :(" << endl << endl;
        return;
    }

    string userInput;

    cout << "\n\tRemoving member from membership ..." << endl;
    cout << "\t___________________________________" << endl;

    cout << "\n\tEnter Member ID : ";
    cin >> userInput;

    Member* curr = head;
    Member* prev = NULL;

    while(curr != NULL){
        if(curr -> ID == userInput){

            if(curr -> totalBookBorrow != 0){
                cout << "\n\tThis member borrowed a book currently";
                cout << "\n\tAbort deletion process ..." << endl << endl;
                return;
            }

            if(prev == NULL){
                head = curr -> next;
            }
            else{
                prev -> next = curr -> next;
            }

            cout << "\n\n\tThe member has been removed successfully :(" << endl << endl;
            delete curr;
            totalMember--;
            return;
        }
        prev = curr;
        curr = curr -> next;
    }

    cout << "\n\tSorry, member with ID " << userInput << " did not exist in the system" << endl << endl;
    return;
}

void Membership::deleteAllMember(){
    if(isEmpty()){
        return;
    }

    Member* curr = head;
    Member* nextMember;
    while(curr != NULL){
        nextMember = curr -> next;
        delete curr;
        curr = nextMember;
    }
    head = NULL;
    totalMember = 0;
    memberIDCounter = 0;
}

void Membership::loadFile(){
    ifstream readFile("memberData.txt");
    if(!readFile.is_open()){
        cout << "\n ERROR! Unable to read from member data ...\n" << endl;
        return;
    }

    queue<Member> Queue;
    string line;
    while(getline(readFile, line)){
        stringstream ss(line);
        string input;

        string ID, name, phoneNum, email;
        int totalBookBorrow;

        getline(ss, ID, '~');
        getline(ss, name, '~');
        getline(ss, phoneNum, '~');
        getline(ss, email, '~');
        getline(ss, input, '~');
        ss >> totalBookBorrow;

        Member temp{ID, name, phoneNum, email, totalBookBorrow, NULL};
        Queue.push(temp);
    }

    while(!Queue.empty()){
        Member curr = Queue.front();
        Queue.pop();

        addMember(curr.ID, curr.name, curr.phoneNum, curr.email, curr.totalBookBorrow);
    }

    cout << "\n Member data loaded successfully\n" << endl;
    readFile.close();
}

void Membership::saveFile(){
    ofstream writeFile("memberData.txt");
    if(!writeFile.is_open()){
        cout << "\n ERROR! Unable to write into member data ...\n" << endl;
        return;
    }

    Member* curr = head;
    while(curr != NULL){
        writeFile << curr -> ID << '~' << curr -> name << '~'
                  << curr -> phoneNum << '~' << curr -> email << '~'
                  << curr -> totalBookBorrow << endl;
        curr = curr -> next;
    }

    cout << "\n Member data saved successfully\n" << endl;
    writeFile.close();
}