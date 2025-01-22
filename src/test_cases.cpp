#include "../include/Parser.h"
#include "../include/expressions/Expression.h"

#include <bits/stdc++.h>
using namespace std;

void test_expression_interpret(string expr) {
    try {
        Parser parser(expr);
        Expression* parsedExpression = parser.parse();

        // try boolean evaluation
        try {
            bool booleanResult = parsedExpression->evaluate_boolean();
            cout << "Expression: " << expr << " = " << (booleanResult ? "true" : "false") << endl;
        } catch (exception) {
            // if boolean evaluation fails, tries integer evaluation
            int intResult = parsedExpression->evaluate();
            cout << "Expression: " << expr << " = " << intResult << endl;
        }

        // free tree
        delete parsedExpression;
    } catch (const exception e) {
        cerr << "Error while processing \"" << expr << "\": " << e.what() << endl;
    }
}

int test_cases() {
    vector<string> testCases = {
        "7",
        "2 + 3 * 2",
        "( 2 - - -3 ) * 2",
        "3 / 2",
        "true || false == false",
        "( true || false ) == false",
        "true + 3",
    };

    for (const auto testCase : testCases) {
        test_expression_interpret(testCase);
    }

    return 0;
}
