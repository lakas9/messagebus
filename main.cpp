// main.cpp
// Effectively the client that would interact with a fully featured message 
// bus.  This is more of a simulation demonstrating what could happen if this 
// were an actual message bus.  This only should interact with messageBus.hpp 
// which would represent the server aspect of this application. 
// The simulation follows the example and shows proper output when needed.  

#include <iostream>
#include <functional>
#include <queue>
#include <vector>

#include "messageBus.hpp"

int main()
{
    MessageBus messageBus;

    cout << "Create users and forum" << endl << endl;
    messageBus.createUser("Alice");
    messageBus.createUser("Bob");
    messageBus.createUser("Carol");

    messageBus.createForum("foo");
    messageBus.createForum("bar");

    messageBus.setForumByName("foo");

    messageBus.addUserToForum("Alice");
    messageBus.addUserToForum("Carol");

    messageBus.setForumByName("bar");

    messageBus.addUserToForum("Bob");
    messageBus.addUserToForum("Carol");

    cout << "Alice sends message to foo" << endl << endl;
    messageBus.setForumByName("foo");
    messageBus.setUserByName("Alice");

    messageBus.sendMsg("Hello, World!");

    messageBus.setUserByName("Carol");
    messageBus.pullAllMessages();

    messageBus.setUserByName("Bob");
    messageBus.pullAllMessages();

    cout << endl << "Alice sends message to bar" << endl << endl;

    messageBus.setForumByName("bar");
    messageBus.setUserByName("Alice");

    messageBus.sendMsg("Hello again");

    messageBus.setUserByName("Carol");
    messageBus.pullAllMessages();

    messageBus.setUserByName("Bob");
    messageBus.pullAllMessages();

    cout << endl << "Carol sends message to fiz" << endl << endl;

    messageBus.setForumByName("fiz");
    messageBus.setUserByName("Carol");

    messageBus.sendMsg("Goodbye, cruel world");

    messageBus.setUserByName("Alice");
    messageBus.pullAllMessages();

    messageBus.setUserByName("Bob");
    messageBus.pullAllMessages();

    return 0;
}
