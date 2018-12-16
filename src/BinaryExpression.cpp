//
// Created by ziv_t on 12/14/18.
//

#include <cmath>
#include "BinaryExpression.h"

BinaryExpression::BinaryExpression(Expression* left, Expression* right)  {
    this->leftExp = left;
    this->rightExp = right;
}

BinaryExpression::BinaryExpression(double left, Expression* right) {
    this->leftExp = new Number(left);
    this->rightExp = right;
}

BinaryExpression::BinaryExpression(Expression* left, double right) {
    this->leftExp = left;
    this->rightExp = new Number(right);
}

BinaryExpression::BinaryExpression(double left, double right) {
    this->leftExp = new Number(left);
    this->rightExp = new Number(right);
}

Expression* BinaryExpression::getLeftExp() {
    return this->leftExp;
}

Expression* BinaryExpression::getRightExp() {
    return this->rightExp;
}








