//
// Created by ziv_t on 12/14/18.
//

#ifndef STEPPING_STONE1_OPENSERVERCOMMAND_H
#define STEPPING_STONE1_OPENSERVERCOMMAND_H

#include <string>
#include "Command.h"


class OpenServerCommand:public Command{
public:
    void execute(std::vector<std::string>::iterator &iter) override;

    ~OpenServerCommand() override;

    void addMaps(mapHandler &mapHandler1) override;
};


#endif //STEPPING_STONE1_OPENSERVERCOMMAND_H
