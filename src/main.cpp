#include <iostream>
#include "super-header.h"
#include "vector"

//load script file using lexer function and then parse using parser function.
int main() {
    std::string line;
    std::getline(std::cin,line);
    Interpreter i;
    i.lexer(line);


    return 0;
}

