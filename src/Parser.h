//
// Created by elyawy on 12/18/18.
//

#ifndef STEPPING_STONE1_PARSER_H
#define STEPPING_STONE1_PARSER_H


#include "mapHandler.h"
#include "Expression.h"
#include "Lexer.h"

class Parser {
private:
mapHandler mapH;
std::map<std::string , SECONDSTAGE > *tokens;
public:
    void parse( std::vector<std::string> &toParse , std::map<std::string , SECONDSTAGE > *tokenized);
    void addMaps(mapHandler &mapHandler1);

    void twoArgs( std::vector<std::string> &toParse);

    void oneArg( std::vector<std::string> &toParse);

    Expression * shuntingYard();
};


#endif //STEPPING_STONE1_PARSER_H
