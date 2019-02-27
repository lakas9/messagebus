// message.hpp
// This is the message sent.  The user pointer attached to this object is 
// who sent the message. 

using namespace std;

#ifndef message_hpp
#define message_hpp

class User;

class Message
{
    public:
        Message(string msg)
        {
            message = msg;
        };

        ~Message() {};

        void setUser(User * user) {
            msgUser = user;
        }

        User * getUser() {
            return msgUser;
        }

        string getMessage()
        {
            return message;
        } 

    private:
        string message;
        User * msgUser;

};


#endif