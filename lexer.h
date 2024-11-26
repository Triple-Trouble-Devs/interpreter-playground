#ifndef LEXER_H
#define LEXER_H

#include <string>

class Token {
public:
    enum class Type {
        Identifier,
        Number,
        Plus,
        Minus,
        Multiply,
        Divide,
        Assign,
        Semicolon,
        LeftBrace,
        RightBrace,
        Colon,
        Comma,
        ConsoleLog,
        End
    };

    Token() : type(Type::End), value("") {}

    Token(Type type, const std::string& value = "")
        : type(type), value(value) {}

    Type type;
    std::string value;
};

class Lexer {
public:
    explicit Lexer(const std::string& input);
    Token getNextToken();

private:
    Token parseIdentifier();
    Token parseNumber();

    const std::string& input;
    size_t pos;
};

#endif
