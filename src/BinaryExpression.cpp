//
// Created by ziv_t on 12/14/18.
//

#include <cmath>
#include "BinaryExpression.h"
#include "varExpression.h"

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

BinaryExpression::~BinaryExpression() {
    delete(leftExp);
    delete(rightExp);
}

BinaryExpression::BinaryExpression(std::string &left, std::string &right) {
    if (isdigit(left[0]) && isdigit(right[0])) {
        this->leftExp = new Number(stod(left));
        this->rightExp = new Number(stod(right));
    }
    if (isdigit(left[0]) && isalpha(right[0])) {
        this->leftExp = new Number(stod(left));
        this->rightExp = new varExpression(right);
    }
    if (isalpha(left[0]) && isdigit(right[0])) {
        this->leftExp = new varExpression(left);
        this->rightExp = new Number(stod(right));
    }
    if (isalpha(left[0]) && isalpha(right[0])) {
        this->leftExp = new varExpression(left);
        this->rightExp = new varExpression(right);
    }
}

BinaryExpression::BinaryExpression(Expression *left, std::string &right) {
    if (isdigit(right[0])) {
        this->leftExp = left;
        this->rightExp = new Number(stod(right));
    }
    if (isalpha(right[0])) {
        this->leftExp = left;
        this->rightExp = new varExpression(right);
    }
}








