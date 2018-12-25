//
// Created by elyawy on 12/18/18.
//

#ifndef STEPPING_STONE1_CONDITIONPARSER_H
#define STEPPING_STONE1_CONDITIONPARSER_H


#include "Command.h"
#include "Interpreter.h"

class conditionParser: public Command {
protected:
    std::vector<std::string> commandList;
    Expression * condition;
    Interpreter interpreter;
public:
    conditionParser();
    void execute() override;
    bool checkCondition();

    void loopInitializer();

    void loopStarter();

    void addMaps(mapHandler &mapHandler1) override;

    void jump() override;

};


#endif //STEPPING_STONE1_CONDITIONPARSER_H
