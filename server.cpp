/*
 * ============================================================================
 *
 *       Filename:  server.c
 *
 *    Description:  Simple protocol server implementation
 * ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


/* Server port  */
#define PORT 27015


/* Buffer length */
#define BUFFER_LENGTH 4096



/*
 * Main execution of the server program of the simple protocol
 */
int
main(void) {

    /* Client and Server socket structures */
    struct sockaddr_in client, server;

    /* File descriptors of client and server */
    int serverfd, clientfd;

    char buffer[BUFFER_LENGTH];

    fprintf(stdout, "Starting server\n");

    /* Creates a IPv4 socket */
    serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverfd == -1) {
        perror("Can't create the server socket:");
        return EXIT_FAILURE;
    }
    fprintf(stdout, "Server socket created with fd: %d\n", serverfd);


    /* Defines the server socket properties */
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    memset(server.sin_zero, 0x0, 8);


    /* Handle the error of the port already in use */
    int yes = 1;
    if(setsockopt(serverfd, SOL_SOCKET, SO_REUSEADDR,
                  &yes, sizeof(int)) == -1) {
        perror("Socket options error:");
        return EXIT_FAILURE;
    }


    /* bind the socket to a port */
    if(bind(serverfd, (struct sockaddr*)&server, sizeof(server)) == -1 ) {
        perror("Socket bind error:");
        return EXIT_FAILURE;
    }


    /* Starts to wait connections from clients */
    if(listen(serverfd, 1) == -1) {
        perror("Listen error:");
        return EXIT_FAILURE;
    }
    fprintf(stdout, "Listening on port %d\n", PORT);

    socklen_t client_len = sizeof(client);
    if ((clientfd=accept(serverfd,
        (struct sockaddr *) &client, &client_len )) == -1) {
        perror("Accept error:");
        return EXIT_FAILURE;
    }


    /* Copies into buffer our welcome messaage */
    strcpy(buffer, "\n           _   _   _ _ _             _         \n _____  __| |_| "
"|_| | | | __ ___ ___|_|___ ___ \n|     ||. |  _|   | | | ||. |  _|  "
"_| | . |  _|\n|_|_|_|___| | |_|_|_____|___|_| |_| |_|___|_|  \n      "
"    |__|                                 \n\n Pressione . para ver as instru????es\nou qualquer outra tecla se quiser\n       jogar logo direto!\n\n\0");


    /* Sends the message to the client */
    if (send(clientfd, buffer, strlen(buffer), 0)) {
        fprintf(stdout, "Client connected.\nWaiting for client message ...\n");

        /* Communicates with the client until bye message come */
        do {

            /* Zeroing buffers */
            memset(buffer, 0x0, BUFFER_LENGTH);

            /* Receives client message */
            int message_len;
            if((message_len = recv(clientfd, buffer, BUFFER_LENGTH, 0)) > 0) {
                buffer[message_len - 1] = '\0';
                printf("Client says: %s\n", buffer);
            }


            /* 'bye' message finishes the connection */
            if(strcmp(buffer, ".") == 0) {
                send(clientfd, "\n Instru????es \n\n O jogo consiste de uma mec??nica simples, voc??\n ?? um guerreiro e a sua amada foi raptada pelo\n Escabroso Rei dos Quadrados. Para t??-la de volta\n voc?? ter?? que derrotar os monstros que permeiam \n o reino, os cavaleiros reais e o pr??prio Rei ???.\n\n",259,0);
                send(clientfd, "\n", 1, 0);
            } 
            else {
                send(clientfd, "\n Here we go!!\n\n", 16, 0);
            }
        } while(strcmp(buffer, "."));
    }

    /* Client connection Close */
    close(clientfd);

    /* Close the local socket */
    close(serverfd);

    printf("\n\nConnection closed\n\n");

    return EXIT_SUCCESS;
}
