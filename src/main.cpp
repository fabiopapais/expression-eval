#include "../include/Parser.h"
#include "../include/expressions/Expression.h"

#include <bits/stdc++.h>
using namespace std;

void testExpression(const string expr) {
    Parser parser(expr);
    Expression* parsedExpression = parser.parse();

    float result = parsedExpression->evaluate();

    std::cout << "Expression: " << expr << " = " << result << endl;

    delete parsedExpression; // Cleanup
}

int main() {
    std::vector<std::string> testCases = {
        "7",
        "2 + 3 * 2",
        "( 2 - - -3 ) * 2",
        "3 / 2",
        "true || false == false",
        "( true || false ) == false",
        "true + 3",
    };


    for (const auto& testCase : testCases) {
        testExpression(testCase);
    }

    return 0;
}

// handle boolean + integer operations
// handle boolean operations and comparisons (and output as boolean)
// handle  "( 2 - - -3 ) * 2"