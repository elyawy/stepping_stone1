#include <iostream>
#include "super-header.h"
#include "vector"

//load script file using lexer function and then parse using parser function.
int main() {
    std::string line;
    std::cout << "pull";
    Interpreter i;
    do {
        std::getline(std::cin, line);
        i.lexer(line);
    } while (line != "`");
    return 0;
}

