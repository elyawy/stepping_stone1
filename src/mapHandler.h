//
// Created by elyawy on 12/17/18.
//

#ifndef STEPPING_STONE1_MAPHANDLER_H
#define STEPPING_STONE1_MAPHANDLER_H

#include <string>
#include <map>
#include <vector>
#include "Lexer.h"
#include <queue>
#include "fstream"

class Expression;

class mapHandler {
private:
    std::map<std::string, double> *symblTable;
    std::map<std::string, std::string> *vartoBindTable;
    std::vector<std::string> *toParse;
    std::queue<std::string> *parseQueue;
    std::queue<std::string> *parsed;
    std::map<std::string, SECONDSTAGE> *tokens;
    std::map<std::string, Expression*> *expressList;
    std::ifstream *myfile;

public:
    void setSymbleMap(std::map<std::string, double> *symblTable1);
    void setvartobindMap(std::map<std::string, std::string> *vartoBindTable1);
    void settoParse(std::vector<std::string> *toParse);
    void setParsed(std::queue<std::string> *toParse);
    void setparseQueue(std::queue<std::string> *parse1);
    void setTokens(std::map<std::string, SECONDSTAGE> *tokens1);
    void setExpresssions(std::map<std::string, Expression*> *expressList1);
    void setStream(std::ifstream *file);

    std::ifstream *getStream();
    std::map<std::string, SECONDSTAGE > *getTokens();
    std::map<std::string, std::string> * getvartobindMap();
    std::map<std::string, double> * getsymblTable();
    std::vector<std::string> *gettoParse();
    std::queue<std::string> *getParsed();
    std::queue<std::string> *getparseQueue();
    std::map<std::string, Expression*> *getExpressions();
};


#endif //STEPPING_STONE1_MAPHANDLER_H
