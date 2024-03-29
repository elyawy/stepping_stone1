//
// Created by ziv_t on 12/16/18.
//

#ifndef STEPPING_STONE1_MINUS_H
#define STEPPING_STONE1_MINUS_H

#include "BinaryExpression.h"

class Minus : public BinaryExpression {
public:
    Minus(Expression* left, Expression* right);
    Minus(double left, Expression* right);
    Minus(Expression* left, double right);
    Minus(double left, double right);

    Minus(Expression *left, std::string &right);

    Minus(std::string &left, std::string &right);

    double calculate(mapHandler &mapH) override;

    std::string stringify() override;
};


#endif //STEPPING_STONE1_MINUS_H
