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
    std::map<std::string,Expression*> conditionList;
    Interpreter interpreter;
    int level;
public:
    conditionParser();
    void execute() override;
    bool checkCondition();

    void loopInitializer();

    void loopStarter();

    void addMaps(mapHandler &mapHandler1) override;

    void jump() override;

    void setCommandlist(std::vector<std::string> *commandlist);
    void setCondition(Expression *exp);
};


#endif //STEPPING_STONE1_CONDITIONPARSER_H
