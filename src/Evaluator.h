//
// Created by elyawy on 12/21/18.
//

#ifndef STEPPING_STONE1_EVALUATOR_H
#define STEPPING_STONE1_EVALUATOR_H


#include "Expression.h"
#include <queue>

class Evaluator {

public:
    Expression * analizer(std::string &express);

    Expression * shuntingYard(std::string &express);

    int operatorValue(std::string &a);

    bool isOperator(std::string &a);

    Expression * expressionBuilder(std::vector<std::string> &queue);

    bool isNum(std::string &a);
};


#endif //STEPPING_STONE1_EVALUATOR_H
