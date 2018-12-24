//
// Created by elyawy on 12/18/18.
//

#ifndef STEPPING_STONE1_CONDITIONPARSER_H
#define STEPPING_STONE1_CONDITIONPARSER_H


#include "Command.h"
#include "list"
#include "Interpreter.h"

class conditionParser: public Command {
protected:
    std::list<Expression*> commandList;
    Interpreter interpreter;
public:

    void execute() override;
    bool checkCondition();

    void addTokens(std::map<std::string , SECONDSTAGE > *tokenized1) override;


    void addMaps(mapHandler &mapHandler1) override;

};


#endif //STEPPING_STONE1_CONDITIONPARSER_H
