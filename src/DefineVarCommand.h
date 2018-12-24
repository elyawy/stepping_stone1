//
// Created by elyawy on 12/16/18.
//

#ifndef STEPPING_STONE1_VAR_H
#define STEPPING_STONE1_VAR_H


#include <string>
#include "Command.h"


class DefineVarCommand: public Command {
public:
    void execute() override;

    ~DefineVarCommand() override;

    void addMaps(mapHandler &mapHandler1) override;
    void addTokens(std::map<std::string , SECONDSTAGE > *tokenized1) override;


};


#endif //STEPPING_STONE1_VAR_H
