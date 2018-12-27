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
#include <iostream>


void OpenServerCommand::execute() {
    double portno = this->mapH.getExpressions()->at(this->mapH.getparseQueue()->front())->calculate(mapH);
    if (portno == 5400) {
        std::cout << "the server is open!\n";
    }
    int sockfd, newsockfd, clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    double  n;
    std::vector<std::string> var = {"/instrumentation/airspeed-indicator/indicated-speed-kt",
                                    "/instrumentation/altimeter/indicated-altitude-ft",
                                    "/instrumentation/altimeter/pressure-alt-ft",
                                    "/instrumentation/attitude-indicator/indicated-pitch-deg",
                                    "/instrumentation/attitude-indicator/indicated-roll-deg",
                                    "/instrumentation/attitude-indicator/internal-pitch-deg",
                                    "/instrumentation/attitude-indicator/internal-roll-deg",
                                    "/instrumentation/encoder/indicated-altitude-ft",
                                    "/instrumentation/encoder/pressure-alt-ft",
                                    "/instrumentation/gps/indicated-altitude-ft",
                                    "/instrumentation/gps/indicated-ground-speed-kt",
                                    "/instrumentation/gps/indicated-vertical-speed",
                                    "/instrumentation/heading-indicator/indicated-heading-deg",
                                    "/instrumentation/magnetic-compass/indicated-heading-deg",
                                    "/instrumentation/slip-skid-ball/indicated-slip-skid",
                                    "/instrumentation/turn-indicator/indicated-turn-rate",
                                    "/instrumentation/vertical-speed-indicator/indicated-speed-fpm",
                                    "/controls/flight/aileron",
                                    "/controls/flight/elevator",
                                    "/controls/flight/rudder",
                                    "/controls/flight/flaps",
                                    "/controls/engines/engine/throttle",
                                    "/engines/engine/rpm"};

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
    * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd,5);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    /* If connection is established then start communicating */
    while (true) {
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        /* Push all argument from server to a vector */
        std::istringstream iss(buffer);
        std::queue<std::string> fromSer;
        while(!iss.eof()) {
            int i = 1;
            std::string temp = "";
            iss >> temp;
            std::cout << temp << "\n";
            std::string delim = ",";
            auto start = 0U;
            auto end = temp.find(delim);
            while (end != std::string::npos)
            {
                fromSer.push(temp.substr(start, end - start));
                start = end + delim.length();
                end = temp.find(delim, start);

            }
            while (!fromSer.empty()) {
                std::cout << var.at(i) << " -> " << fromSer.front() << "\n";
                fromSer.pop();
                i++;
            }
        }

        /* Write a response to the client */
        n = write(newsockfd, "I got your message", 18);

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }
    }
}

void OpenServerCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string OpenServerCommand::stringify() {
    return std::__cxx11::string();
}


OpenServerCommand::~OpenServerCommand() = default;
