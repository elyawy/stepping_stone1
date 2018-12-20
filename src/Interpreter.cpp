//
// Created by elyawy on 12/12/18.
//

#include <iostream>
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
    mapH.setCommandTable(CommandTable);

    std::map<std::string, Command * >::iterator iter;
    for (iter = CommandTable.begin(); iter != CommandTable.end(); iter++){
        (*iter).second->addMaps(this->mapH);
    }
    p.addMaps(mapH);
    l.addMaps(mapH);

}



