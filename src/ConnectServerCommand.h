//
// Created by elyawy on 12/16/18.
//

#ifndef STEPPING_STONE1_CONNECTSERVERCOMMAND_H
#define STEPPING_STONE1_CONNECTSERVERCOMMAND_H


#include "Command.h"

class ConnectServerCommand: public Command {
public:
    void execute(std::vector<std::string>::iterator &iter) override;

    void addSymblMapPointer(std::map<std::string, double> &symblTable) override;

};


#endif //STEPPING_STONE1_CONNECTSERVERCOMMAND_H
