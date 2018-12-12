//
// Created by elyawy on 12/12/18.
//

#ifndef STEPPING_STONE1_INTERPRETER_H
#define STEPPING_STONE1_INTERPRETER_H


#include <string>
#include <map>
#include <vector>


class Interpreter {
private:
std::map<std::string, double > symblTable;
std::vector<std::string> toParse;

public:

void lexer(std::string & line);

void parser();



};


#endif //STEPPING_STONE1_INTERPRETER_H
