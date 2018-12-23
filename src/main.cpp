#include <iostream>
#include "test.h"
#include "ExpTest.h"
#include "Interpreter.h"
#include "mapHandler.h"
//load script file using lexer function and then parse using parser function.
int main() {
    std::string line = "";
    double result;
    Interpreter i;
    Evaluator E;
    mapHandler H;
    std::string temp = " 3 * 3";
    Expression* exp;
    exp = E.analizer(temp);
    result = exp->calculate(H);

    delete(exp);
//    do {
//        std::getline(std::cin, line);
//        if(line == "`") break;
//        if(line.empty()) continue;
//
////        i.lexer(line);
////        i.parser();
//    } while (line != "`");
    return 0;
}
