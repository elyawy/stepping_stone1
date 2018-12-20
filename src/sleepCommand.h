//
// Created by elyawy on 12/16/18.
//

#ifndef STEPPING_STONE1_SLEEPCOMMAND_H
#define STEPPING_STONE1_SLEEPCOMMAND_H


#include "Command.h"

class sleepCommand: public Command {
public:
    void execute(std::vector<std::string>::iterator &iter) override;

    void addMaps(mapHandler &mapHandler1) override;
    void addTokens(std::map<std::string , SECONDSTAGE > *tokenized1) override;

};


#endif //STEPPING_STONE1_SLEEPCOMMAND_H
