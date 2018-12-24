//
// Created by elyawy on 12/18/18.
//

#ifndef STEPPING_STONE1_BINDCOMMAND_H
#define STEPPING_STONE1_BINDCOMMAND_H


#include "Command.h"

class bindCommand: public Command {
public:
    void execute() override;

    ~bindCommand() override;

    void addMaps(mapHandler &mapHandler1) override;


};

#endif //STEPPING_STONE1_BINDCOMMAND_H
