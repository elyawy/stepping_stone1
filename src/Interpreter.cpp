//
// Created by elyawy on 12/12/18.
//

#include "Interpreter.h"



void Interpreter::lexer(std::string& line) {
    l.lex(line,toParse);
    tokenized = l.getTOKENS();
    mapH.setTokens(tokenized);
    std::cout << "passed" << std::endl;
}

void Interpreter::parser() {
    p.addMaps(mapH);
    p.parse(toParse, tokenized);
}




Interpreter::Interpreter() {
    mapH.setSymbleMap(symblTable);
    mapH.setbindtovarMap(bindtoVarTable);
    mapH.setbindtovarMap(vartoBindTable);
    mapH.settoParse(toParse);
    mapH.setExpresssions(ExpressTable);

}

mapHandler *Interpreter::getMapH() {
    return &mapH;
}



