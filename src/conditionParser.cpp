//
// Created by elyawy on 12/18/18.
//

#include "conditionParser.h"

void conditionParser::execute() {
}




bool conditionParser::checkCondition() {
    return (bool)condition->calculate(mapH);
}


void conditionParser::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}





conditionParser::conditionParser() = default;

void conditionParser::loopInitializer() {
    condition = mapH.getExpressions()->at(mapH.getparseQueue()->front());
    interpreter.getMapH()->setSymbleMap(mapH.getsymblTable());
    jump();
    std::string line;
    do {
        std::getline(std::cin, line);
        if(line == "`") break;
        if(line.empty()) continue;

        interpreter.lexer(line);
        interpreter.parser();
    } while (!line.find('}'));
}

void conditionParser::jump() {
    mapH.getParsed()->push(mapH.getparseQueue()->front());
    mapH.getparseQueue()->pop();
}
