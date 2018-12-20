//
// Created by elyawy on 12/12/18.
//

#include "Interpreter.h"



void Interpreter::lexer(std::string& line) {
    l.lex(line,toParse);
    tokenized = l.getTOKENS();
    std::cout << "passed" << std::endl;
}

void Interpreter::parser() {
p.parse(toParse, tokenized);
}




Interpreter::Interpreter() {
    mapH.setSymbleMap(symblTable);
    mapH.setbindtovarMap(bindtoVarTable);
    mapH.setbindtovarMap(vartoBindTable);
    mapH.settoParse(toParse);

    p.addMaps(mapH);
}

mapHandler *Interpreter::getMapH() {
    return &mapH;
}



