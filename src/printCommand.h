//
// Created by elyawy on 12/16/18.
//

#ifndef STEPPING_STONE1_PRINTCOMMAND_H
#define STEPPING_STONE1_PRINTCOMMAND_H


#include "Command.h"


class printCommand: public Command {
public:
    void execute(std::vector<std::string>::iterator &iter) override;

    void addMaps(mapHandler &mapHandler1) override;

};


#endif //STEPPING_STONE1_PRINTCOMMAND_H
