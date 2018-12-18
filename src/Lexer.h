//
// Created by elyawy on 12/18/18.
//

#ifndef STEPPING_STONE1_LEXER_H
#define STEPPING_STONE1_LEXER_H

#include "string"
#include "vector"


class Lexer {
public:
    void lex(std::string& line, std::vector<std::string> &toParse);

};


#endif //STEPPING_STONE1_LEXER_H
