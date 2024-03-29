//
// Created by ziv_t on 12/16/18.
//

#ifndef STEPPING_STONE1_DIV_H
#define STEPPING_STONE1_DIV_H

#include "BinaryExpression.h"

class Div : public BinaryExpression{
public:
    Div(Expression* left, Expression* right);
    Div(double left, Expression* right);
    Div(Expression* left, double right);

    Div(Expression *left, std::string &right);


    Div(std::string &left, std::string &right);

    Div(double left, double right);
    double calculate(mapHandler &mapH) override;

    std::string stringify() override;
};


#endif //STEPPING_STONE1_DIV_H
