//
// Created by elyawy on 12/16/18.
//

#include <iostream>
#include "printCommand.h"
#include <algorithm>

void printCommand::execute(std::vector<std::string>::iterator &iter) {
    if (mapH.getExpressions()->count("evaluate")>0){
        std::cout << mapH.getExpressions()->at("evaluate")->calculate(mapH) << std::endl;
    }
    if (mapH.getExpressions()->count("to_print")>0){
        mapH.getExpressions()->at("to_print")->calculate(mapH);
    }
}

void printCommand::addMaps(mapHandler &mapHandler1) {
    mapH = mapHandler1;
}

void printCommand::addTokens(std::map<std::string, SECONDSTAGE> *tokenized1) {
    tokenized = tokenized1;

}
