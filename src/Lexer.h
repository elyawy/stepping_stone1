//
// Created by elyawy on 12/18/18.
//

#ifndef STEPPING_STONE1_LEXER_H
#define STEPPING_STONE1_LEXER_H

#include "string"
#include "vector"
#include "map"


enum TOKENS{Bracketstart, CurlBracketstart,Bracketend,CurlBracketend,
        quote, number, ADD, SUBSTRACT,DIVIDE,MULTIPLY, EQUAL, SPACE, LETTER, Conditional, OTHER, POINT };

enum SECONDSTAGE {VARIABLE, KEYWORD, TOEVALUTE, QUOTED, FUNCSTART, FUNCEND, EQUALS, IP};

class Lexer {
    std::map<int , TOKENS > token_list;
    std::map<std::string , SECONDSTAGE > scanned_list;
    std::vector<std::string> *toParse;
public:
    void lex(std::string& line, std::vector<std::string> &toParse);

    void tokenizer(std::string& line);

    void tokenize(char &a, int location);

    void quotes(std::string &line, int &i);

    void Brackets(std::string &line, int &i);

    void Parethesis(std::string &line, int &i);

    void Words(std::string &line, int &i);

    void Ip(std::string &line, int &i);

    void Express(std::string &line, int &i);

    void equals(std::string &line, int &i);

    void Conditions(std::string &line, int &i);

    void Printer(std::string &line, int &i);

    std::map<std::string , SECONDSTAGE > * getTOKENS();

    bool isCommand(std::string &temp);
};


#endif //STEPPING_STONE1_LEXER_H
