#include <cstdlib>
using namespace std;
#ifndef MEMBER_HPP
#define MEMBER_HPP

namespace MemberSys{

class Membership{
    private:
        struct Member{
            string ID, name, phoneNum, email;
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
        
        void addMember();
        void addMember(const string& ID, const string& name,
                       const string& phoneNum, const string& email);
        void displayAllMember();
        void viewMemberInfo();
        void editMember();
        void deleteMember();
        void deleteAllMember();

        void loadFile();
        void saveFile();
};

};

#endif