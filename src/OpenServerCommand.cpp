#include <memory>

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
#include <algorithm>
#include <thread>
#include <mutex>


void OpenServerCommand::execute() {
    double portno = this->mapH.getExpressions()->at(this->mapH.getparseQueue()->front())->calculate(mapH);
    jump();
    double sleepTime = 1000 / this->mapH.getExpressions()->at(this->mapH.getparseQueue()->front())->calculate(mapH);
    if (portno == 5400) {
        std::cout << "the server is open!\n";
    }
    jump();
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
    std::thread *fromServer = new std::thread(&OpenServerCommand::connectAndUpdate, this, sleepTime, newsockfd);
    serverthread = fromServer;
}

void OpenServerCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

std::string OpenServerCommand::stringify() {
    return std::__cxx11::string();
}

void OpenServerCommand::connectAndUpdate(int sleepTime, int sockeNum) {
    std::mutex mtx;
    std::queue<std::string> varQueue;

    char buffer[256];
    double  n;

    /* If connection is established then start communicating */
    while (true) {
        bzero(buffer, 256);

        n = read(sockeNum, buffer, 255);
        if(flag){
            break;
        }

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
//            std::cout << temp << "\n";
            std::string delim = ",";
            auto start = 0U;
            auto end = temp.find(delim);
            while (end != std::string::npos)
            {
                fromSer.push_back(temp.substr(start, end - start));
                start = static_cast<unsigned int>(end + delim.length());
                end = temp.find(delim, start);
            }
            int j = 0;
            while (j < fromSer.size()){
                double x = stod(fromSer[j]);
                std::string path = DirectVar[j];
                mtx.lock();
                if (!mapH.getvartobindMap()->empty()) {
                    std::map<std::string, std::string>::iterator mapIndx;
                    for(mapIndx = mapH.getvartobindMap()->begin(); mapIndx != mapH.getvartobindMap()->end(); mapIndx++ ){
                        std::string check((*mapIndx).second.begin()+1,(*mapIndx).second.end()-1);
                        if (check == path){
                            varQueue.push((*mapIndx).first);
                        }
                    }
                    while (!varQueue.empty()){
                        mapH.getsymblTable()->at(varQueue.front()) = x;
                        varQueue.pop();
                    }
                }
                mtx.unlock();
                j++;
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



OpenServerCommand::~OpenServerCommand(){
flag = true;
serverthread->join();
delete serverthread;
}
