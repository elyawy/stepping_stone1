//
// Created by elyawy on 12/16/18.
//

#ifndef STEPPING_STONE1_CONNECTSERVERCOMMAND_H
#define STEPPING_STONE1_CONNECTSERVERCOMMAND_H


#include "Command.h"

class ConnectServerCommand: public Command {
private:
    bool socketIsOpen = false;
    int socketServer;
public:
    void execute() override;
    int connect(std::string ip_num, double port_num);
    int sendMassage();
    void addMaps(mapHandler &mapHandler1) override;

    std::string stringify() override;
    ~ConnectServerCommand();
};


#endif //STEPPING_STONE1_CONNECTSERVERCOMMAND_H
