//
// Created by elyawy on 12/12/18.
//

#ifndef STEPPING_STONE1_EXPRESSION_H
#define STEPPING_STONE1_EXPRESSION_H

#include <string>
#include <vector>
#include "mapHandler.h"

class Expression {
public:
    virtual double calculate(mapHandler &mapH) = 0;

    virtual std::string stringify() = 0;

    virtual ~Expression() = default;;

    virtual void jump(mapHandler &mapH){}

};


#endif //STEPPING_STONE1_EXPRESSION_H
