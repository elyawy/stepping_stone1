//
// Created by elyawy on 12/23/18.
//

#ifndef STEPPING_STONE1_QUOTEDEXPRESSION_H
#define STEPPING_STONE1_QUOTEDEXPRESSION_H


#include "Expression.h"

class quotedExpression: public Expression {
    std::string toPrint;
public:
    explicit quotedExpression(std::string &quote);
    double calculate(mapHandler &mapH) override;

    std::string stringify() override;
};


#endif //STEPPING_STONE1_QUOTEDEXPRESSION_H
