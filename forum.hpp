// forum.hpp
// This is the location of the forum.  This object can have <= 0 users as 
// members.  This also sends the physical message. 


using namespace std;

#include "user.hpp"

class Forum
{
    public:
        Forum(const string forumname)
        {
            forumName = forumname;
        }
        ~Forum() {};

        void addUser(User *user) {
            userList.push_back(user);
        }

        string getForum() {
            return forumName;
        }

        void sendMessage(User * user, Message *message) {
            message->setUser(user);
            for (iter = userList.begin(); iter != userList.end(); iter++) {
                if (user->getUserName() != (*iter)->getUserName()) {
                   (*iter)->receiveMessage(message);
                }
            }
        }

    private:
        vector<User *> userList;
        vector<User *>::iterator iter;
        string forumName;
};