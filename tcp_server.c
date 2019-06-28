/*
"Server" Socket Workflow

Create a socket with the socket() call,
bind() the socket to an IP and port
where it can listen() for connections,
and then accept() a connection
and send() or recv() data to the other sockets
it is connected to.

FLow:
        socket()
            |
            v
        bind()
            |
            v
        listen()
            |
            v
        accept()
*/

#include <stdio.h>
#include <stdlib.h>

// definitions for socket functions
#include <sys/types.h>
#include <sys/socket.h>

// to store address information
#include <netinet/in.h>

// tcp client
int main() {

        // socket() call
        int server_socket;

        /*
        *  call socket function and store in  an integer
        *  AF_INET      =       domain (AF_INET -> internet socket)
        *  SOCK_STREAM  =       type of the socket (SOCK_STREAM -> tcp)
        *  0            =       protocol (0 -> default protocol (tcp))
        */
        server_socket = socket(AF_INET, SOCK_STREAM, 0);

        /*
        * we need to connect to another socket (client)
        * we use the netinet header to we know the remote socket we connect to
        */
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;            // specify address family
        server_address.sin_port = htons(9002);          // specify the port with conversion function (htons)
        server_address.sin_addr.s_addr = INADDR_ANY;    // specify the actual address (local host)
        
	// bind() call 
        /*
        * call the bind() function
        * network_socket                        =       actual socket
        * (struct sockaddr *) &server_address   =       cast server address structure
        * size_of(server_address)               =       size of the address
        */
        bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));

	listen(server_socket, 5);

	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);

	// send() call
	char server_message[256] = "Happy day.";

	send(client_socket, server_message, sizeof(server_message), 0);

        close(server_socket);                                                  // close socket

        return 0;

}
        
