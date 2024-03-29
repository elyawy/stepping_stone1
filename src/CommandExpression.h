//
// Created by elyawy on 12/16/18.
//

#ifndef STEPPING_STONE1_COMMANDEXPRESSION_H
#define STEPPING_STONE1_COMMANDEXPRESSION_H


#include "Expression.h"
#include "Command.h"
#include <vector>


class CommandExpression: public Expression {
private:
    Command *command;

public:
    explicit CommandExpression(Command *command);

    double calculate(mapHandler &mapH) override;

    ~CommandExpression() override;

    std::string stringify() override;

};


#endif //STEPPING_STONE1_COMMANDEXPRESSION_H
