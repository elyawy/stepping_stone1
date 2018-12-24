//
// Created by elyawy on 12/16/18.
//

#ifndef STEPPING_STONE1_WHILECOMMAND_H
#define STEPPING_STONE1_WHILECOMMAND_H


#include "Command.h"
#include "conditionParser.h"

class whileCommand: public conditionParser {
public:
    void execute() override;
    void addMaps(mapHandler &mapHandler1) override;

    std::string stringify() override;
};


#endif //STEPPING_STONE1_WHILECOMMAND_H
