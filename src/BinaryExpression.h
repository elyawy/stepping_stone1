//
// Created by ziv_t on 12/14/18.
//

#ifndef STEPPING_STONE1_BINARYEXPRESSION_H
#define STEPPING_STONE1_BINARYEXPRESSION_H

#include "Expression.h"
#include "Number.h"

class BinaryExpression : public Expression {
private:
    Expression* rightExp;
    Expression* leftExp;
public:
    BinaryExpression(Expression* left, Expression* right);
    BinaryExpression(double left, Expression* right);
    BinaryExpression(Expression* left, double right);
    BinaryExpression(double left, double right);
    virtual double calculate() = 0;
    Expression* getLeftExp();
    Expression* getRightExp();
};


#endif //STEPPING_STONE1_BINARYEXPRESSION_H
