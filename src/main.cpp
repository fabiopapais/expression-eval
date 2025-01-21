#include "../include/Parser.h"
#include "../include/expressions/Expression.h"

#include <bits/stdc++.h>
using namespace std;

void testExpression(const string expr) {
    try {
        Parser parser(expr);
        Expression* parsedExpression = parser.parse();

        int result = parsedExpression->evaluate();

        std::cout << "Expression: " << expr << " = " << result << endl;

        delete parsedExpression; // Cleanup
    } catch (exception e) {
        cerr << "Error parsing expression '" << expr << "': " << e.what() << endl;
    }
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