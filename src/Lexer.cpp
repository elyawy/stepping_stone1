//
// Created by elyawy on 12/18/18.
//

#include <sstream>
#include <vector>
#include "Lexer.h"

void Lexer::lex(std::string &line, std::vector<std::string> &toParse) {
    std::istringstream iss(line);
    while(!iss.eof()) {
        std::string temp;
        iss >> temp;
        toParse.push_back(temp);
    }

}
