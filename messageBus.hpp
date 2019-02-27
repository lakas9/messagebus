// MessageBus.hpp
// This is probably an improper representation of what a Message Bus should
// be if implemented with servers, clients, and a message service.  
// This is the location where everyone will interact using a client with 
// adding users/forums and becoming members of those forums.  
//
// Anytime a user is created the private pointer to the user is changed to
// point to that user.  In the real world this wouldnt happen because Bob, for instance, 
// would be the user tied to the client connecting to the bus.  The same is for the forum. 
// This exists in this example due to it being a simulation.  

using namespace std;

#include "forum.hpp"

class MessageBus
{
    public:
        MessageBus() {};
        ~MessageBus() {}; 

        Forum * getForumBus() {
            return forum;
        }

        User * getUserBus() {
            return user;
        }

        void setUserByName(string name) {
            for (iterUser = userList.begin(); iterUser != userList.end(); iterUser++) {
                if (name == (*iterUser)->getUserName()) {
                   user = *iterUser;
                   return;
                }
            }
            createUser(name);
        }

        void setForumByName(string name) {
            for (iterForum = forumList.begin(); iterForum != forumList.end(); iterForum++) {
                if (name == (*iterForum)->getForum()) {
                   forum = *iterForum;
                   return;
                }
            }
            createForum(name);
        }

        void createUser(string name) {
            User *cuser = new User(name);
            this->user = cuser;
            this->userList.push_back(cuser);
        }

        void createForum(string name) {
            Forum *cforum = new Forum(name);
            this->forum = cforum;
            this->forumList.push_back(cforum);
        }

        void sendMsg(string messagestr) {
            Message *message = new Message(messagestr);
            getForumBus()->sendMessage(user, message);
        }

        void addUserToForum(string userName) {
            setUserByName(userName);
            getForumBus()->addUser(getUserBus());
            
        }

        void pullAllMessages() {
            getUserBus()->showAll();
        }


    protected:
        Forum * forum;
        User * user;

        void setUser(User * puser) {
            user = puser;
        }

        void setForum(Forum * pforum) {
            forum = pforum;
        }

    private:
        vector<Forum *> forumList;
        vector<Forum *>::iterator iterForum;
        vector<User *> userList;
        vector<User *>::iterator iterUser;
};