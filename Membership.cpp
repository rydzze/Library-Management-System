#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <queue>
#include "Membership.hpp"
using namespace std;
using namespace MemberSys;

//check again display and view func for interface
//adjust interface for add and edit func
//add variable to see what book they borrow
// then readjust view member info func

Membership::Membership() : head(NULL), totalMember(0){}

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

void Membership::addMember(){
    string userInput;

    Member* newMember = new Member;
    cout << "\nFull Name     : ";
    getline(cin, userInput);
    newMember -> name = userInput;
    cout << "\nPhone Number  : ";
    newMember -> phoneNum = userInput;
    cout << "\nEmail Address : ";
    newMember -> email = userInput;
    newMember -> ID = generateMemberID();

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

void Membership::addMember(const string& ID, const string& name,
                           const string& phoneNum, const string& email)
{
    Member* newMember = new Member;
    newMember -> ID = ID;
    newMember -> name = name;
    newMember -> phoneNum = phoneNum;
    newMember -> email = email;
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
        cout << "\nNo member registered ...\n";
        return;
    }

    Member* curr = head;
    //implement display, refer Library
}

void Membership::viewMemberInfo(){
    if(isEmpty()){
        return;
    }
    
    string userInput;
    cout << "\nEnter Member ID : ";
    cin >> userInput;

    Member* curr = head;
    //implement view, refer Library
}

void Membership::editMember(){
    if(isEmpty()){
        return;
    }
    
    string userInput;
    cout << "\nEnter Member ID : ";
    cin >> userInput;

    Member* curr = new Member;
    while(curr != NULL){
        if(curr -> ID == userInput){
            cout<<"\nEditing member with ID "<< curr -> ID << endl;

            cout << "\nFull Name     : ";
            getline(cin, userInput);
            curr -> name = userInput;
            cout << "\nPhone Number  : ";
            curr -> phoneNum = userInput;
            cout << "\nEmail Address : ";
            curr -> email = userInput;

            cout << "\nMember with ID " << curr -> ID << " edited successfully ...\n";
            return;
        }
        curr = curr -> next;
    }
    cout << "\nMember didn't exist in system ...\n";
    return;
}

void Membership::deleteMember(){
    if(isEmpty()){
        return;
    }

    string userInput;
    cout << "\nEnter Member ID : ";
    cin >> userInput;

    Member* curr = head;
    Member* prev = NULL;

    while(curr != NULL){
        if(curr -> ID == userInput){
            if(prev == NULL){
                head = curr -> next;
            }
            else{
                prev -> next = curr -> next;
            }

            cout << "\nMember with ID " << userInput << " removed successfully ...\n";
            delete curr;
            totalMember--;
            return;
        }
        prev = curr;
        curr = curr -> next;
    }

    cout << "\nMember with ID " << userInput << " not found ...\n";
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
}

void Membership::loadFile(){
    ifstream readFile("memberData.txt");
    if(!readFile.is_open()){
        cout << "\nError: Unable to open file for reading." << endl;
        return;
    }

    queue<Member> Queue;
    string line;
    while(getline(readFile, line)){
        stringstream ss(line);
        string ID, name, phoneNum, email;

        getline(ss, ID, '~');
        getline(ss, name, '~');
        getline(ss, phoneNum, '~');
        getline(ss, email, '~');

        Member temp{ID, name, phoneNum, email, NULL};
        Queue.push(temp);
    }

    while(!Queue.empty()){
        Member curr = Queue.front();
        Queue.pop();

        addMember(curr.ID, curr.name, curr.phoneNum, curr.email);
    }

    cout << "\n Member data loaded successfully" << endl;
    readFile.close();
}

void Membership::saveFile(){
    ofstream writeFile("memberData.txt");
    if(!writeFile.is_open()){
        cout << "\nError: Unable to open file for writing." << endl;
        return;
    }

    Member* curr = head;
    while(curr != NULL){
        writeFile << curr -> ID << '~' << curr -> name << '~'
                  << curr -> phoneNum << '~' << curr -> email << '~' << endl;
        curr = curr -> next;
    }

    cout << "\n Member data saved successfully" << endl;
    writeFile.close();
}