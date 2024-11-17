#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <map>
#include <string>

class Parser {
public:
    explicit Parser(Lexer& lexer);
    void parse(); 

    std::map<std::string, int> getVariables() const;
    std::map<std::string, std::map<std::string, int>> getObjects() const;

private:
    Lexer& lexer;
    Token currentToken;

    std::map<std::string, int> variables;
    std::map<std::string, std::map<std::string, int>> objects;

    void advance();
    void parseVariableDeclaration();
    std::map<std::string, int> parseObjectLiteral();
};

#endif
