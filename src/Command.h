//
// Created by elyawy on 12/12/18.
//

#ifndef STEPPING_STONE1_COMMAND_H
#define STEPPING_STONE1_COMMAND_H


#include <string>
#include <vector>

class Command {
public:
    virtual void execute(std::vector<std::string>::iterator &iter){}
    virtual ~Command() = default;
};



#endif //STEPPING_STONE1_COMMAND_H
