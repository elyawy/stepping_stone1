//
// Created by elyawy on 12/16/18.
//

#ifndef STEPPING_STONE1_CONNECTSERVERCOMMAND_H
#define STEPPING_STONE1_CONNECTSERVERCOMMAND_H


#include <thread>
#include "Command.h"

class ConnectServerCommand: public Command {
    int socketServerNum;
    bool sockIsOpen = false;
    std::thread *serverthread; // the connect function's thread.
    bool flag = false;
public:
    void execute() override;
    int connect(std::string ip_num, double port_num);
    int sendMassage(std::string message, double value, ...);
    void addMaps(mapHandler &mapHandler1) override;
    void updateConnection();

    std::string stringify() override;
    ~ConnectServerCommand();
};


#endif //STEPPING_STONE1_CONNECTSERVERCOMMAND_H
