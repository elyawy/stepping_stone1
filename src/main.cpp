#include <iostream>

#include "super-header.h"
#include "Lexer.h"

#include "vector"
std::vector<std::string>  lexer();

//load script file using lexer function and then parse using parser function.
int main() {
    std::cout << "hi, World!" << std::endl;
    lexer();



    return 0;
}


std::vector<std::string> lexer(){
    Lexer l;
    return l.readScript();
}

