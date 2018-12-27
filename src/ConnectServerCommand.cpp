//
// Created by elyawy on 12/16/18.
//

#include "ConnectServerCommand.h"
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdarg.h>
#include <string.h>


void ConnectServerCommand::execute() {
 std::string ip_num = this->mapH.getparseQueue()->front();
 this->mapH.getParsed()->push(ip_num);
 this->mapH.getparseQueue()->pop();
 double port_num = this->mapH.getExpressions()->at(this->mapH.getparseQueue()->front())->calculate(mapH);
 this->mapH.getParsed()->push(this->mapH.getparseQueue()->front());
 this->mapH.getparseQueue()->pop();
 socketServerNum = connect(ip_num, port_num);

 std::thread *fromServer = new std::thread(&ConnectServerCommand::updateConnection, this);
 serverthread = fromServer;
}

void ConnectServerCommand::addMaps(mapHandler &mapHandler1) {
 mapH =mapHandler1;
}

std::string ConnectServerCommand::stringify() {
 return std::__cxx11::string();
}

int ConnectServerCommand::connect(std::string ip_num, double port_num) {
 char hostname[ip_num.length()];
 strcpy(hostname, ip_num.c_str());
 struct sockaddr_in serv_addr;
 struct hostent *hostinfo;
 int sock;

 sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
 if (sock < 0) {
  perror("fgfsconnect/socket");
  return -1;
 }

 hostinfo = gethostbyname(hostname);
 if (hostinfo == NULL) {
  fprintf(stderr, "fgfsconnect: unknown host: \"%s\"\n", hostname);
  close(sock);
  return -2;
 }

 serv_addr.sin_family = AF_INET;
 serv_addr.sin_port = htons(port_num);
 serv_addr.sin_addr = *(struct in_addr *)hostinfo->h_addr;

 if (::connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
  perror("fgfsconnect/connect");
  close(sock);
  return -3;
 }
 if (sock < 0) {
  return EXIT_FAILURE;
 }
 sockIsOpen = true;
 return sock;
}

int ConnectServerCommand::sendMassage(std::string message, double value, ...) {
 std::string finalMsg = "set ";
 std::string newmessage(message.begin()+1, message.end()-1);
 finalMsg.append(newmessage).append(" ").append(std::to_string(value));
 char msg[finalMsg.length()];
 strcpy(msg, finalMsg.c_str());
 va_list va;
 ssize_t len;
 char buf[256];

 va_start(va, msg);
 vsnprintf(buf, 256 - 2, msg, va);
 va_end(va);
 printf("SEND: \t<%s>\n", buf);
 strcat(buf, "\015\012");

 len = write(socketServerNum, buf, strlen(buf));
 if (len < 0) {
  perror("fgfswrite");
  exit(EXIT_FAILURE);
 }
 return (int)len;
}

ConnectServerCommand::~ConnectServerCommand() {
 close(socketServerNum);
 sockIsOpen = false;
 flag = true;
 serverthread->join();
 delete serverthread;
}

void ConnectServerCommand::updateConnection() {
 while (sockIsOpen) {
  if(flag){
   break;
  }
  if (!mapH.getUpdated()->empty()) {
   std::string msg = mapH.getvartobindMap()->at(mapH.getUpdated()->front());
   double value = mapH.getsymblTable()->at(mapH.getUpdated()->front());
   sendMassage(msg, value);
   mapH.getUpdated()->pop();
  }
 }
}



