//
// Created by elyawy on 12/16/18.
//

#ifndef STEPPING_STONE1_VAR_H
#define STEPPING_STONE1_VAR_H


#include <string>
#include "Command.h"

class DefineVarCommand: public Command {
private:
    std::string var;
public:
    void execute() override;

    DefineVarCommand(int x, int y);
    ~DefineVarCommand() override;


};


#endif //STEPPING_STONE1_VAR_H
