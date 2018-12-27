#include <iostream>
#include <fstream>
#include "test.h"
#include "ExpTest.h"
#include "Interpreter.h"
#include "mapHandler.h"


//load script file using lexer function and then parse using parser function.
int main(int argc, char *argv[]) {
    std::ifstream myfile;
    if (argc >=2){
        std::string filename = argv[1];
        myfile.open(filename);
    }
    std::string line;
    Interpreter i;
    i.getMapH()->setStream(&myfile);
        do {
        if (myfile.is_open()){
            std::getline(myfile, line);
        } else std::getline(std::cin, line);
        if(line.find("exit") != std::string::npos)   break;
        if(line.empty()) continue;
        i.lexer(line);
        i.parser();
        i.Calculator();
    } while (line.find("exit") == std::string::npos && !myfile.eof());
        myfile.close();
       // std::cin >> line;
    return 0;
}