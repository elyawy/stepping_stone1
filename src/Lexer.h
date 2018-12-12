//
// Created by elyawy on 12/12/18.
//

#ifndef STEPPING_STONE1_LEXER_H
#define STEPPING_STONE1_LEXER_H


#include <string>
#include <vector>

class Lexer {
private:
    std::vector<std::string> text;
public:
    std::vector<std::string>  readScript();

};


#endif //STEPPING_STONE1_LEXER_H
