//
// Created by ziv_t on 12/16/18.
//

#ifndef STEPPING_STONE1_MUL_H
#define STEPPING_STONE1_MUL_H

#include "BinaryExpression.h"

class Mul : public BinaryExpression {
public:
    Mul(Expression* left, Expression* right);
    Mul(double left, Expression* right);
    Mul(Expression* left, double right);
    Mul(double left, double right);

    Mul(Expression *left, std::string &right);

    Mul(std::string &left, std::string &right);

    double calculate(mapHandler &mapH) override;

    std::string stringify() override;
};


#endif //STEPPING_STONE1_MUL_H
