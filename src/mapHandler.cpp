//
// Created by elyawy on 12/17/18.
//

#include "mapHandler.h"

std::map<std::string, std::string> *mapHandler::getbindtovarMap() {
    return bindtoVarTable;
}

std::map<std::string, std::string> *mapHandler::getvartobindMap() {
    return vartoBindTable;
}

std::map<std::string, double> *mapHandler::getsymblTable() {
    return symblTable;
}

void mapHandler::setSymbleMap(std::map<std::string, double> &symblTable1) {
    symblTable = &symblTable1;
}

void mapHandler::setvartobindMap(std::map<std::string, std::string> &vartoBindTable1) {
 vartoBindTable = &vartoBindTable1;
}

void mapHandler::setbindtovarMap(std::map<std::string, std::string> &bindtoVarTable1) {
 bindtoVarTable = &bindtoVarTable1;
}

std::vector<std::string> *mapHandler::gettoParse() {
    return toParse;
}

void mapHandler::settoParse(std::vector<std::string> &toParse1) {
    toParse = &toParse1;
}

void mapHandler::setTokens(std::map<std::string, SECONDSTAGE> *tokens1) {
    tokens = tokens1;
}

std::map<std::string, SECONDSTAGE> *mapHandler::getTokens() {
    return tokens;
}



