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
        int network_socket;

        /*
        *  call socket function and store in  an integer
        *  AF_INET      =       domain (AF_INET -> internet socket)
        *  SOCK_STREAM  =       type of the socket (SOCK_STREAM -> tcp)
        *  0            =       protocol (0 -> default protocol (tcp))
        */
        network_socket = socket(AF_INET, SOCK_STREAM, 0);

        // bind() call
        /*
        * we need to connect to another socket (client)
        * we use the netinet header to we know the remote socket we connect to
        */
        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;            // specify address family
        server_address.sin_port = htons(9002);          // specify the port with conversion function (htons)
        server_address.sin_addr.s_addr = INADDR_ANY;    // specify the actual address (local host)
        
 
        /*
        * call the connect function
        * network_socket                        =       actual socket
        * (struct sockaddr *) &server_address   =       cast server address structure
        * size_of(server_address)               =       size of the address
        */
        connect(network_socket, (struct sockaddr *) &server_address, size_of(server_address);

        /*
        * primitive error handling
        * int connection_status = connect(network_socket, (struct sockaddr *) &server_address, size_of(server_address);
        * if (connection_status == -1) {
        *       printf("Some error");
        * }
        */

        // listen() call
        char server_response[256];                                              // string to hold data from server

        /*
        * call the receive function
        * network_socket                        =       socket
        * &server_response                      =       location data will end up
        * sizeof(server_response)               =       how much space we have
        * 0                                     =       optional flags parameter
        */
        recv(network_socket, &server_response, sizeof(server_response), 0);     // call the receive function

        printf("recv'd: %s\n");                                                 // print response

        close(network_socket);                                                  // close socket

        // accept() call


        return 0;

}
        
