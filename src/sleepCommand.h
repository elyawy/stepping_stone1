//
// Created by elyawy on 12/16/18.
//

#ifndef STEPPING_STONE1_SLEEPCOMMAND_H
#define STEPPING_STONE1_SLEEPCOMMAND_H


#include "Command.h"

class sleepCommand: public Command {
public:
    void execute() override;

    void addMaps(mapHandler &mapHandler1) override;

    std::string stringify() override;
};


#endif //STEPPING_STONE1_SLEEPCOMMAND_H
