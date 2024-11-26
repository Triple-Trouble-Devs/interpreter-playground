#include "parser.h"
#include "iostream"
#include <stdexcept>

Parser::Parser(Lexer& lexer) : lexer(lexer) {
    advance(); 
}

void Parser::advance() {
    currentToken = lexer.getNextToken();
}

void Parser::parse() {
    while (currentToken.type != Token::Type::End) {
        if (currentToken.type == Token::Type::Identifier && currentToken.value == "const") {
            parseVariableDeclaration();
        } else {
            std::cout << "Property Name: " << currentToken.value << std::endl;
            throw std::runtime_error("Unexpected token");
        }
    }
}

void Parser::parseVariableDeclaration() {
    advance(); // Skip 'const'
    if (currentToken.type != Token::Type::Identifier) {
        throw std::runtime_error("Expected variable name");
    }
    std::string varName = currentToken.value;
    advance(); // Skip variable name

    if (currentToken.type != Token::Type::Assign) {
        throw std::runtime_error("Expected '='");
    }
    advance(); // Skip '='

    if (currentToken.type == Token::Type::Number) {
        variables[varName] = std::stoi(currentToken.value);
        advance(); // Move past number
    } else if (currentToken.type == Token::Type::LeftBrace) {
        advance(); // Skip '{'
        objects[varName] = parseObjectLiteral();
    } else {
        throw std::runtime_error("Expected number or object");
    }

    if (currentToken.type != Token::Type::Semicolon) {
        throw std::runtime_error("Expected ';'");
    }
    advance(); 
}

std::map<std::string, int> Parser::parseObjectLiteral() {
    std::map<std::string, int> object;
    
    while (currentToken.type != Token::Type::RightBrace) {
        std::cout << "Property Name: " << currentToken.value << std::endl;

        if (currentToken.type != Token::Type::Identifier) {
            throw std::runtime_error("Expected property name");
        }
        std::string propertyName = currentToken.value;
        advance();

        if (currentToken.type != Token::Type::Colon) {
            throw std::runtime_error("Expected ':'");
        }
        advance(); // Skip ':'

        if (currentToken.type != Token::Type::Number) {
            throw std::runtime_error("Expected number");
        }
        int value = std::stoi(currentToken.value);
        object[propertyName] = value;
        advance();

        if (currentToken.type == Token::Type::Comma) {
            advance(); // Skip ','
        } else if (currentToken.type != Token::Type::RightBrace) {
            throw std::runtime_error("Expected ',' or '}'");
        }
    }
    advance(); 
    return object;
}

std::map<std::string, int> Parser::getVariables() const {
    return variables;
}

std::map<std::string, std::map<std::string, int>> Parser::getObjects() const {
    return objects;
}
