/*
"Client" Socket Workflow
https://www.youtube.com/watch?v=LtXEMwSG5-8

The client socket is created with socket() call,
and is connected to a remote address with the connect() call,
and then finally we receive the data with the recv() call.

FLow:
        socket()
            |
            v
        connect()
            |
            v
        recv()
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

        // Socket
        int network_socket;

        /*
        *  call socket function and store in  an integer
        *  AF_INET                              =       domain (AF_INET -> internet socket)
        *  SOCK_STREAM                          =       type of the socket (SOCK_STREAM -> tcp)
        *  0                                    =       protocol (0 -> default protocol (tcp))
        */
        network_socket = socket(AF_INET, SOCK_STREAM, 0);                                       // socket() call

        struct sockaddr_in server_address;                                                      // rename and assign sockaddr_in struct
        server_address.sin_family = AF_INET;                                                    // specify address family
        server_address.sin_port = htons(9002);                                                  // specify the port with conversion function (htons)
        server_address.sin_addr.s_addr = INADDR_ANY;                                            // specify the actual address (local host)

        // Connect
        /*
        * we need to connect to another socket (client)
        * we use the netinet header to we know the remote socket we connect to
        */
        /*
        * call the connect function
        * network_socket                        =       actual socket
        * (struct sockaddr *) &server_address   =       cast server address structure
        * size_of(server_address)               =       size of the address
        */
        
        connect(network_socket, (struct sockaddr *) &server_address, size_of(server_address);   // connect() call

        /*
        * primitive error handling
        * int connection_status = connect(network_socket, (struct sockaddr *) &server_address, size_of(server_address);
        * if (connection_status == -1) {
        *       printf("Some error");
        * }
        */

        // Send (Server) or Receive (Client) Data
        char server_response[256];                                                              // string to hold data from server

        /*
        * call the receive function
        * network_socket                        =       socket
        * &server_response                      =       location data will end up
        * sizeof(server_response)               =       how much space we have
        * 0                                     =       optional flags parameter
        */
        recv(network_socket, &server_response, sizeof(server_response), 0);                     // recv() call

        printf("recv'd: %s\n");                                                                 // print response

        close(network_socket);                                                                  // close socket


        return 0;

}
