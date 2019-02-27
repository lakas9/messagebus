//  User.hpp
//  This is effectly the User.  This object stores
//  the messages and displays them when the user requests it.  

using namespace std;

#ifndef user_hpp
#define user_hpp

#include "message.hpp"

class User
{
    public:

        User(const string username)
        {
            userName = username;
        }

        ~User() {};

        string getUserName()
        {
            return userName;
        }

        void receiveMessage(Message *message) {
            messages.push(message);
        }

        void showAll() {
            while(!messages.empty()) {
                Message *first = messages.front();
                User *user = first->getUser();
                string username = user->getUserName();
                cout << "From: " << username << " To: " << getUserName() << " Msg: " << first->getMessage() << std::endl;
                messages.pop();
            }
        }
    private:
        string userName;
        queue<Message *> messages;
};

#endif