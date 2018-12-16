//
// Created by elyawy on 12/12/18.
//

#ifndef STEPPING_STONE1_COMMAND_H
#define STEPPING_STONE1_COMMAND_H


class Command {
public:
    virtual void execute(){}
    virtual ~Command() = default;
};



#endif //STEPPING_STONE1_COMMAND_H
