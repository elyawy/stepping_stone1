//
// Created by elyawy on 12/18/18.
//

#include <fstream>
#include "conditionParser.h"
#include "whileCommand.h"

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
    interpreter.getMapH()->setUpdated(mapH.getUpdated());
    interpreter.getMapH()->setvartobindMap(mapH.getvartobindMap());

    jump();
    std::string line;
    interpreter.getMapH()->setStream(mapH.getStream());
    if (mapH.getparseQueue()->front() != "{") {
        do {
            if (mapH.getStream()->is_open()) {
                std::getline(*mapH.getStream(), line);
            } else std::getline(std::cin, line);
            if (line.empty()) continue;
        } while (line.find('{') == std::string::npos && !mapH.getStream()->eof());
        if (mapH.getStream()->eof()) throw "invalid syntax";
        level++;
    }
    do {
        if (mapH.getStream()->is_open()){
            std::getline(*mapH.getStream(), line);
        } else std::getline(std::cin, line);
        if(line.empty()) continue;
        commandList.push_back(line);
    }while (line.find('}') == std::string::npos && !mapH.getStream()->eof());
    level--;


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

void conditionParser::setCommandlist(std::vector<std::string> *commandlist) {

}

void conditionParser::setCondition(Expression *exp) {

}

