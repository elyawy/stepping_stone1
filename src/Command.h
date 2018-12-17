//
// Created by elyawy on 12/12/18.
//

#ifndef STEPPING_STONE1_COMMAND_H
#define STEPPING_STONE1_COMMAND_H


#include <string>
#include <vector>
#include <map>

class Command {
public:
    std::map<std::string, double>* symblTable;

    virtual void execute(std::vector<std::string>::iterator &iter){}
    virtual ~Command() = default;

    virtual void addSymblMapPointer(std::map<std::string, double> &symblTable){}
};



#endif //STEPPING_STONE1_COMMAND_H
