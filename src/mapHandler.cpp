//
// Created by elyawy on 12/17/18.
//

#include "mapHandler.h"


std::map<std::string, std::string> *mapHandler::getvartobindMap() {
    return vartoBindTable;
}

std::map<std::string, double> *mapHandler::getsymblTable() {
    return symblTable;
}

void mapHandler::setSymbleMap(std::map<std::string, double> *symblTable1) {
    symblTable = symblTable1;
}

void mapHandler::setvartobindMap(std::map<std::string, std::string> *vartoBindTable1) {
 vartoBindTable = vartoBindTable1;
}



std::vector<std::string> *mapHandler::gettoParse() {
    return toParse;
}

void mapHandler::settoParse(std::vector<std::string> *toParse1) {
    toParse = toParse1;
}

void mapHandler::setTokens(std::map<std::string, SECONDSTAGE> *tokens1) {
    tokens = tokens1;
}

std::map<std::string, SECONDSTAGE> *mapHandler::getTokens() {
    return tokens;
}

void mapHandler::setExpresssions(std::map<std::string, Expression *> *expressList1) {
 expressList = expressList1;
}

std::map<std::string, Expression *> *mapHandler::getExpressions() {
    return expressList;
}

void mapHandler::setParsed(std::queue<std::string> *Parsed) {
    parsed = Parsed;
}

std::queue<std::string> *mapHandler::getParsed() {
    return parsed;
}

void mapHandler::setparseQueue(std::queue<std::string> *parse1) {
    parseQueue =parse1;
}

std::queue<std::string> *mapHandler::getparseQueue() {
    return parseQueue;
}

void mapHandler::setStream(std::ifstream *file) {
    myfile = file;
}

std::ifstream *mapHandler::getStream() {
    return myfile;
}

void mapHandler::setUpdated(std::queue<std::string> *update) {
    updated = update;
}

std::queue<std::string> *mapHandler::getUpdated() {
    return updated;
}







