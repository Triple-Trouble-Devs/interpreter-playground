#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "parser.h"

class Evaluator {
public:
    explicit Evaluator(Parser& parser);
    void execute();

private:
    Parser& parser;

    void evaluateConsoleLog();
};

#endif
