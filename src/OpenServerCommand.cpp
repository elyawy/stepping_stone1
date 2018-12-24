//
// Created by ziv_t on 12/14/18.
//

#include "OpenServerCommand.h"
#include <cstdio>
#include <cstdlib>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <cstring>

#include <sys/socket.h>
#include <sstream>


void OpenServerCommand::execute() {
//    std::string port = *iter;
//    ++iter;
//    int sockfd, newsockfd, clilen;
//    char buffer[256];
//    struct sockaddr_in serv_addr, cli_addr;
//    double  n, portno;
//
//    /* First call to socket() function */
//    sockfd = socket(AF_INET, SOCK_STREAM, 0);
//     if (sockfd < 0) {
//         perror("ERROR opening socket");
//         exit(1);
//     }
//
//     /* Initialize socket structure */
//     bzero((char *) &serv_addr, sizeof(serv_addr));
//     portno = std::stoi(port);
//
//     serv_addr.sin_family = AF_INET;
//     serv_addr.sin_addr.s_addr = INADDR_ANY;
//     serv_addr.sin_port = htons(portno);
//
//     /* Now bind the host address using bind() call.*/
//     if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
//         perror("ERROR on binding");
//         exit(1);
//     }
//
//     /* Now start listening for the clients, here process will
//     * go in sleep mode and will wait for the incoming connection
//     */
//
//     listen(sockfd,5);
//     clilen = sizeof(cli_addr);
//
//     /* Accept actual connection from the client */
//     newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
//
//     if (newsockfd < 0) {
//         perror("ERROR on accept");
//         exit(1);
//     }
//
//     /* If connection is established then start communicating */
//     while (true) {
//         bzero(buffer, 256);
//         n = read(newsockfd, buffer, 255);
//
//         if (n < 0) {
//             perror("ERROR reading from socket");
//             exit(1);
//         }
//
//     /* Push all argument from server to a vector */
//         std::istringstream iss(buffer);
//         while(!iss.eof()) {
//             std::string temp;
//             iss >> temp;
//             fromServerToMap.push_back(temp);
//         }
//
//         printf("Here is the message: %s\n", buffer);
//
//         /* Write a response to the client */
//         n = write(newsockfd, "I got your message", 18);
//
//         if (n < 0) {
//             perror("ERROR writing to socket");
//             exit(1);
//         }
//     }
}

void OpenServerCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

void OpenServerCommand::addTokens(std::map<std::string, SECONDSTAGE> *tokenized1) {
    tokenized = tokenized1;

}

OpenServerCommand::~OpenServerCommand() = default;
