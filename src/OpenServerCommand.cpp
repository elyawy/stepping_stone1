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
#include <thread>
#include <algorithm>


void OpenServerCommand::execute() {
    double portno = this->mapH.getExpressions()->at(this->mapH.getparseQueue()->front())->calculate(mapH);
    jump();
    double sleepTime = 1000 / this->mapH.getExpressions()->at(this->mapH.getparseQueue()->front())->calculate(mapH);
    if (portno == 5400) {
        std::cout << "the server is open!\n";
    }
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;

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
    serv_addr.sin_port = htons(static_cast<uint16_t>(portno));

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
    std::thread fromServer(&OpenServerCommand::connectAndUpdate, this,  sleepTime,  sockfd);
    fromServer.detach();

}

void OpenServerCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string OpenServerCommand::stringify() {
    return std::__cxx11::string();
}

void OpenServerCommand::connectAndUpdate(int sleepTime, int sockeNum) {
    char buffer[256];
    double  n;
    /* If connection is established then start communicating */
    while (true) {
        bzero(buffer, 256);
        n = read(sockeNum, buffer, 255);

        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        /* Push all argument from server to a vector */
        std::istringstream iss(buffer);
        std::vector<std::string> fromSer;
        while(!iss.eof()) {
            int i = 1;
            std::string temp;
            iss >> temp;
            std::cout << temp << "\n";
            std::string delim = ",";
            auto start = 0U;
            auto end = temp.find(delim);
            while (end != std::string::npos)
            {
                fromSer.push_back(temp.substr(start, end - start));
                start = static_cast<unsigned int>(end + delim.length());
                end = temp.find(delim, start);
            }
            std::map<std::string, std::string>::iterator mapIndx;
            for (mapIndx = mapH.getvartobindMap()->begin(); mapIndx != mapH.getvartobindMap()->end(); ++mapIndx) {
                int inxd = findIndexFromString(mapIndx->second);
                if (inxd != -1) {
                    mapH.getsymblTable()->at(mapIndx->second) = std::stoi(fromSer.at(inxd));
                }
            }
        }

        /* Write a response to the client */
        n = write(sockeNum, "I got your message", 18);

        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        }



        usleep(static_cast<__useconds_t>(sleepTime));
    }
}

int OpenServerCommand::findIndexFromString(std::string const &path) const {
    ptrdiff_t pos = find(this->DirectVar.begin(), this->DirectVar.end(), path) - this->DirectVar.begin();
    if (pos >= this->DirectVar.size()) {
        perror("PATH NOT FOUND IN VECTOR");
        return -1;
    }
    return static_cast<int>(pos);
}


OpenServerCommand::~OpenServerCommand() = default;
