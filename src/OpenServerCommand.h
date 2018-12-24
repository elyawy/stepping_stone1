//
// Created by ziv_t on 12/14/18.
//

#ifndef STEPPING_STONE1_OPENSERVERCOMMAND_H
#define STEPPING_STONE1_OPENSERVERCOMMAND_H

#include <string>
#include "Command.h"

class OpenServerCommand:public Command{
    std::vector<std::string> fromServerToMap;
public:
    void execute() override;

    ~OpenServerCommand() override;

    std::string stringify() override;

    void addMaps(mapHandler &mapHandler1) override;

};


#endif //STEPPING_STONE1_OPENSERVERCOMMAND_H
