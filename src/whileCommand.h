//
// Created by elyawy on 12/16/18.
//

#ifndef STEPPING_STONE1_WHILECOMMAND_H
#define STEPPING_STONE1_WHILECOMMAND_H


#include "Command.h"

class whileCommand: public Command {
public:
    void execute(std::vector<std::string>::iterator &iter) override;
};


#endif //STEPPING_STONE1_WHILECOMMAND_H
