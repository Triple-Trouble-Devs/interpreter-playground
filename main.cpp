#include "lexer.h"
#include "parser.h"
#include "evaluator.h"
#include <iostream>
#include <string>

int main() {
    std::string code;
    std::cout << "Enter JavaScript code: ";
    std::getline(std::cin, code);

    try {
        Lexer lexer(code);
        Parser parser(lexer);
        Evaluator evaluator(parser);
        evaluator.execute();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}