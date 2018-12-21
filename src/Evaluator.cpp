//
// Created by elyawy on 12/21/18.
//

#include "Evaluator.h"

Expression *Evaluator::analizer(std::string &express) {
    int i = 0;
    std::string temp;
    while (i < express.size()){
        temp+= express[i];
      if (express[i] == '<' || '>' || '='){

        // booleanExpression creator.

        // return boolean expression.
       }
        i++;
    }

}

Expression *Evaluator::shuntingYard() {

    return nullptr;
}