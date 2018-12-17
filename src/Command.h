//
// Created by elyawy on 12/12/18.
//

#ifndef STEPPING_STONE1_COMMAND_H
#define STEPPING_STONE1_COMMAND_H


#include <string>
#include <vector>
#include <map>
#include "mapHandler.h"

class Command {
protected:
    mapHandler mapH;
public:

    virtual void execute(std::vector<std::string>::iterator &iter){}
    virtual ~Command() = default;

    virtual void addMaps(mapHandler &mapHandler1){}
};



#endif //STEPPING_STONE1_COMMAND_H
