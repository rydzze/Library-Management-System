#include <cstdlib>
using namespace std;
#ifndef MEMBER_HPP
#define MEMBER_HPP

namespace MemberSys{

class Membership{
    private:
        struct Member{
            string ID, name, phoneNum, email;
            int totalBookBorrow;
            Member* next;
        };
        int totalMember = 0, memberIDCounter = 0;
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
        void updateTotalBookBorrow(const string& ID, const string& status);
        
        void addMember();
        void addMember(const string& ID, const string& name, const string& phoneNum,
                       const string& email, const int& totalBookBorrow);
        void displayAllMember();
        void editMember();
        void deleteMember();
        void deleteAllMember();

        void loadFile();
        void saveFile();
};

};

#endif