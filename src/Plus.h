//
// Created by ziv_t on 12/15/18.
//

#ifndef STEPPING_STONE1_PLUS_H
#define STEPPING_STONE1_PLUS_H

#include "BinaryExpression.h"

class Plus :public BinaryExpression{
public:
    Plus(Expression* left, Expression* right);
    Plus(double left, Expression* right);
    Plus(Expression* left, double right);
    Plus(double left, double right);
    double calculate() override;
};


#endif //STEPPING_STONE1_PLUS_H
