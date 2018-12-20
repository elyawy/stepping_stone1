//
// Created by elyawy on 12/17/18.
//

#ifndef STEPPING_STONE1_MAPHANDLER_H
#define STEPPING_STONE1_MAPHANDLER_H

#include <string>
#include <map>
#include <vector>
#include "Lexer.h"

class mapHandler {
private:
    std::map<std::string, double> *symblTable;
    std::map<std::string, std::string> *vartoBindTable;
    std::map<std::string, std::string> *bindtoVarTable;
    std::vector<std::string> *toParse;
    std::map<std::string, SECONDSTAGE > *tokens;
public:
    void setSymbleMap(std::map<std::string, double> &symblTable1);
    void setvartobindMap(std::map<std::string, std::string> &vartoBindTable1);
    void setbindtovarMap(std::map<std::string, std::string> &bindtoVarTable1);
    void settoParse(std::vector<std::string> &toParse);
    void setTokens(std::map<std::string, SECONDSTAGE> *tokens1);

    std::map<std::string, SECONDSTAGE > *getTokens();
    std::map<std::string, std::string> * getbindtovarMap();
    std::map<std::string, std::string> * getvartobindMap();
    std::map<std::string, double> * getsymblTable();
    std::vector<std::string> *gettoParse();
};


#endif //STEPPING_STONE1_MAPHANDLER_H
