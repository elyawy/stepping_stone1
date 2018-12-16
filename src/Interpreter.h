//
// Created by elyawy on 12/12/18.
//

#ifndef STEPPING_STONE1_INTERPRETER_H
#define STEPPING_STONE1_INTERPRETER_H


#include <string>
#include <map>
#include <vector>
#include "Command.h"
#include "Expression.h"


class Interpreter {
private:
std::map<std::string, Expression*> symblTable;
std::map<std::string, Expression*> ExpressTable;
std::map<std::string, Command*> CommandTable;
std::vector<std::string> toParse;

public:


void lexer(std::string & line);

void parser();



};


#endif //STEPPING_STONE1_INTERPRETER_H
