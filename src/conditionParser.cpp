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
        if (line.find('}') != std::string::npos) break;
        if(line.empty()) continue;
        commandList.push_back(line);
    } while (line.find('}') == std::string::npos);
}

void conditionParser::jump() {
    mapH.getParsed()->push(mapH.getparseQueue()->front());
    mapH.getparseQueue()->pop();
}

void conditionParser::loopStarter() {
    int i = 0;
    while (i < commandList.size()){
        std::string line = commandList[i];
        i++;
        if(line.empty()) continue;
        interpreter.lexer(line);
        interpreter.parser();
        interpreter.Calculator();
    }
}
