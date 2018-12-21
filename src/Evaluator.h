//
// Created by elyawy on 12/21/18.
//

#ifndef STEPPING_STONE1_EVALUATOR_H
#define STEPPING_STONE1_EVALUATOR_H


#include "Expression.h"

class Evaluator {


    Expression * analizer(std::string &express);

    Expression * shuntingYard();


};


#endif //STEPPING_STONE1_EVALUATOR_H
