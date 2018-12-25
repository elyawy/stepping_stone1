//
// Created by elyawy on 12/25/18.
//

#ifndef STEPPING_STONE1_IFCOMMAND_H
#define STEPPING_STONE1_IFCOMMAND_H


#include "Command.h"
#include "conditionParser.h"

class ifCommand: public conditionParser {
public:
    void execute() override;

    void addMaps(mapHandler &mapHandler1) override;

    std::string stringify() override;
};


#endif //STEPPING_STONE1_IFCOMMAND_H
