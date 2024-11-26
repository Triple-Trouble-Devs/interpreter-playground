#include "evaluator.h"
#include <iostream>

Evaluator::Evaluator(Parser& parser) : parser(parser) {}

void Evaluator::execute() {
    parser.parse();

    const auto& variables = parser.getVariables();
    const auto& objects = parser.getObjects();

    evaluateConsoleLog(); 
}

void Evaluator::evaluateConsoleLog() {
    const auto& variables = parser.getVariables();
    const auto& objects = parser.getObjects();

    if (variables.find("a") != variables.end() && objects.find("b") != objects.end()) {
        const auto& bObject = objects.at("b");
        if (bObject.find("c") != bObject.end()) {
            std::cout << variables.at("a") + bObject.at("c") << std::endl;
        }
    }
}
