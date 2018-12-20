//
// Created by elyawy on 12/18/18.
//

#ifndef STEPPING_STONE1_CONDITIONPARSER_H
#define STEPPING_STONE1_CONDITIONPARSER_H


#include "Command.h"
#include "list"

class conditionParser: public Command {
protected:
    std::list<Command*> commandList;
public:
    void execute(std::vector<std::string>::iterator &iter) override;
    bool checkCondition(std::vector<std::string>::iterator &iter);

    void addTokens(std::map<std::string , SECONDSTAGE > *tokenized1) override;


    void addMaps(mapHandler &mapHandler1) override;

    bool lessthan(std::vector<std::string>::iterator &iter);

    bool biggerthan(std::vector<std::string>::iterator &iter);

    bool equalto(std::vector<std::string>::iterator &iter);

};


#endif //STEPPING_STONE1_CONDITIONPARSER_H
