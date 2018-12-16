//
// Created by ziv_t on 12/15/18.
//

#include "Plus.h"

Plus::Plus(Expression *left, Expression *right) : BinaryExpression(left, right) {

}

Plus::Plus(double left, Expression *right) : BinaryExpression(left, right) {

}

Plus::Plus(Expression *left, double right) : BinaryExpression(left, right) {

}

Plus::Plus(double left, double right) : BinaryExpression(left, right) {

}

double Plus::calculate() {
    return this->getLeftExp()->calculate() + this->getRightExp()->calculate();
}





