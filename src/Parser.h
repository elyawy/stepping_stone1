//
// Created by elyawy on 12/18/18.
//

#ifndef STEPPING_STONE1_PARSER_H
#define STEPPING_STONE1_PARSER_H


#include "mapHandler.h"

class Parser {
private:
mapHandler mapH;
public:
    void parse( std::vector<std::string> &toParse);
    void addMaps(mapHandler &mapHandler1);


};


#endif //STEPPING_STONE1_PARSER_H
