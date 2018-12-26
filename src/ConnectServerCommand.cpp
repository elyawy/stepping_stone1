//
// Created by elyawy on 12/16/18.
//

#include "ConnectServerCommand.h"
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <unistd.h>

void ConnectServerCommand::execute() {
 std::string ip_num = this->mapH.getparseQueue()->front();
 this->mapH.getParsed()->push(ip_num);
 this->mapH.getparseQueue()->pop();
 double port_num = this->mapH.getExpressions()->at(this->mapH.getparseQueue()->front())->calculate(mapH);
 this->mapH.getParsed()->push(this->mapH.getparseQueue()->front());
 this->mapH.getparseQueue()->pop();
 connect(ip_num, port_num);
}

void ConnectServerCommand::addMaps(mapHandler &mapHandler1) {
 mapH =mapHandler1;
}

std::string ConnectServerCommand::stringify() {
 return std::__cxx11::string();
}

int ConnectServerCommand::connect(std::string ip_num, double port_num) {
 struct sockaddr_in address{};
 struct sockaddr_in serv_addr{};
 int sock = 0;
 char ip_address [ip_num.length()];
 std::strcpy(ip_address, ip_num.c_str());

 if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
 {
  printf("\n Socket creation error \n");
  return -1;
 }

 memset(&serv_addr, '0', sizeof(serv_addr));

 serv_addr.sin_family = AF_INET;
 serv_addr.sin_port = htons(port_num);

 // Convert IPv4 and IPv6 addresses from text to binary form
 if(inet_pton(AF_INET, ip_address, &serv_addr.sin_addr)<=0)
 {
  printf("\nInvalid address/ Address not supported \n");
  return -1;
 }

 if ( ::connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr))< 0)
 {
  printf("\nConnection Failed \n");
  return -1;
 }
 this->socketServer = sock;
 this->socketIsOpen = true;

 return 0;
}

int ConnectServerCommand::sendMassage() {
 //convert the message to char*
 char mess_char [message.length()];
 strcpy(mess_char, message.c_str());

 char buffer[1024] = {0};

 //sent the message throw the socket
 if(send(this->socketServer , mess_char , strlen(mess_char) , 0 )<0)
  std::cout<<"ERROR in sending message"<<std::endl;
}

ConnectServerCommand::~ConnectServerCommand() {
 this->socketIsOpen = false;
 close(this->socketServer);
}

