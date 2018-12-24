//
// Created by elyawy on 12/18/18.
//

#include "conditionParser.h"

void conditionParser::execute() {
    checkCondition();

}




bool conditionParser::checkCondition() {

}


void conditionParser::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}



conditionParser::conditionParser() {
    interpreter.getMapH()->setSymbleMap(mapH.getsymblTable());
    std::string line;
    do {
        std::getline(std::cin, line);
        if(line == "`") break;
        if(line.empty()) continue;

        interpreter.lexer(line);
        interpreter.parser();
    } while (!line.find('}'));
}