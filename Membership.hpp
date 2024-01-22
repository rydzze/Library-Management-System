#include <cstdlib>
using namespace std;
#ifndef MEMBER_HPP
#define MEMBER_HPP

namespace MemberSys{

class Membership{
    private:
        struct Member{
            string ID, name, phoneNum, email;
            bool borrowStatus;
            Member* next;
        };

        int totalMember, memberIDCounter;
        Member* head;

    public:
        Membership();
        ~Membership();

        bool isEmpty();
        int getTotalMember();
        int getMemberIDCounter();
        string generateMemberID();

        bool checkMembership(const string& ID);
        string getName(const string& ID);
        void changeBorrowStatus(const string& ID);
        
        void addMember();
        void addMember(const string& ID, const string& name, const string& phoneNum,
                       const string& email, const bool& borrowStatus);
        void displayAllMember();
        void editMember();
        void deleteMember();
        void deleteAllMember();

        void loadFile();
        void saveFile();
};

};

#endif