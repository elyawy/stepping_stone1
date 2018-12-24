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


void conditionParser::addTokens(std::map<std::string, SECONDSTAGE> *tokenized1) {
    tokenized = tokenized1;

}
