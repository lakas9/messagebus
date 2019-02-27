# Design and implement a Message Bus

Due to time constraints this is effectively a simulation.  An attempt was made to integrate with an open source message solution such as AMPQ and ZEROMQ.  However their drivers were either out of date or incompatible with the most recent solutions resulting in missing libraries.  

Being a simulation, running the application will just go through the example steps.  

# There are a few things missing from the requirements: 
*  Clients must be able to be distributed over an IPv4 network with no assumption of a local area network or single subnet. 

This has no tcp/ip network interface due to the above situation. 

*  While the implementation may be written in a single language or framework, the message bus must allow for clients to be implemented in other common languages or runtimes.

This is also not possible due to a lack of tcp/ip network interface.  Using an open source messaging solution would have fulfilled this requirement even if completely written in C++.  

This has been compiled in c++14 on a modern linux platform.  The binary is included.  
