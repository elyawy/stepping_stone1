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
