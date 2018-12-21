#include <iostream>
#include "test.h"
#include "ExpTest.h"
#include "Interpreter.h"
//load script file using lexer function and then parse using parser function.
int main() {
    std::string line;
    Interpreter i;
    Evaluator E;
    std::string temp = "2/(throttle -5) + x";
    E.analizer(temp);
    do {
        std::getline(std::cin, line);
        if(line == "`") break;
        if(line.empty()) continue;

//        i.lexer(line);
//        i.parser();
    } while (line != "`");
    return 0;
}
