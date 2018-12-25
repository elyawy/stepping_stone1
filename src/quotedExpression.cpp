//
// Created by elyawy on 12/23/18.
//

#include <iostream>
#include "quotedExpression.h"

double quotedExpression::calculate(mapHandler &mapH) {
    mapH.getParsed()->push(mapH.getparseQueue()->front());
    mapH.getparseQueue()->pop();
    std::cout << toPrint << std::endl;
}

quotedExpression::quotedExpression(std::string &quote) {
 std::string quoteless(quote.begin()+1, quote.end()-1);
 toPrint = quoteless;
}

std::string quotedExpression::stringify() {
    return toPrint;
}
