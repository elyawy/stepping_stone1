//
// Created by elyawy on 12/25/18.
//

#ifndef STEPPING_STONE1_REDEFINEVARCOMMAND_H
#define STEPPING_STONE1_REDEFINEVARCOMMAND_H


#include "Command.h"

class redefineVarCommand: public Command {
public:
    void execute() override;

    void addMaps(mapHandler &mapHandler1) override;

    std::string stringify() override;

    void jump() override;
};


#endif //STEPPING_STONE1_REDEFINEVARCOMMAND_H
