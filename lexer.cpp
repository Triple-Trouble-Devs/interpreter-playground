#include "lexer.h"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string& input) : input(input), pos(0) {}

Token Lexer::getNextToken() {
    while (pos < input.size() && std::isspace(input[pos])) pos++;
    if (pos == input.size()) return Token(Token::Type::End);

    char current = input[pos];

    if (std::isalpha(current)) return parseIdentifier();
    if (std::isdigit(current)) return parseNumber();

    switch (current) {
        case '+': pos++; return Token(Token::Type::Plus);
        case '-': pos++; return Token(Token::Type::Minus);
        case '*': pos++; return Token(Token::Type::Multiply);
        case '/': pos++; return Token(Token::Type::Divide);
        case '=': pos++; return Token(Token::Type::Assign);
        case ';': pos++; return Token(Token::Type::Semicolon);
        case '{': pos++; return Token(Token::Type::LeftBrace);
        case '}': pos++; return Token(Token::Type::RightBrace);
        case ':': pos++; return Token(Token::Type::Colon);
        case ',': pos++; return Token(Token::Type::Comma);
        default: throw std::runtime_error("Invalid character");
    }
}

Token Lexer::parseIdentifier() {
    std::string identifier;
    while (pos < input.size() && std::isalnum(input[pos])) {
        identifier += input[pos++];
    }
    if (identifier == "console" && pos < input.size() && input.substr(pos, 4) == ".log") {
        pos += 4; // Skip over ".log"
        return Token(Token::Type::ConsoleLog);
    }
    return Token(Token::Type::Identifier, identifier);
}

Token Lexer::parseNumber() {
    std::string number;
    while (pos < input.size() && std::isdigit(input[pos])) {
        number += input[pos++];
    }
    return Token(Token::Type::Number, number);
}
