//
// Created by elyawy on 12/12/18.
//

#ifndef STEPPING_STONE1_COMMAND_H
#define STEPPING_STONE1_COMMAND_H

#include <string>
#include <vector>
#include <map>
#include "mapHandler.h"
#include "Lexer.h"
#include "Expression.h"

class Command {
protected:
    mapHandler mapH;
    std::map<std::string , SECONDSTAGE > *tokenized;
public:

    virtual void execute(){}
    virtual ~Command() = default;

    virtual void addTokens(std::map<std::string , SECONDSTAGE > *tokenized1){}

    virtual void addMaps(mapHandler &mapHandler1){}
};



#endif //STEPPING_STONE1_COMMAND_H
