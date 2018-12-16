//
// Created by ziv_t on 12/14/18.
//

#ifndef STEPPING_STONE1_NUMBER_H
#define STEPPING_STONE1_NUMBER_H

#include "Expression.h"


class Number : public Expression{
private:
    double num;
public:
    Number(double number);
    virtual double calculate();
    double getNum();
};


#endif //STEPPING_STONE1_NUMBER_H
