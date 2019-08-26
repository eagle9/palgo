unix socket programming
kind of primitive and hard to test 
concept: ip address, port, treat socket as file, create socket as if it is file
set options, listen for connection, accept the connection from the backlog queue

server2:   connect with mulitple clients without multithreading
     use select command, select one of the active connections

just quick review, not much worth
https://www.geeksforgeeks.org/socket-programming-in-cc-handling-multiple-clients-on-server-without-multi-threading/
socket programming experience in internation fax forwarding project jiarong 
