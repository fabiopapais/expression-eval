#include "../include/Parser.h"
#include "../include/expressions/Expression.h"

#include <bits/stdc++.h>
using namespace std;

void test_expression(string expr) {
    try {
        Parser parser(expr);
        Expression* parsedExpression = parser.parse();

        // try boolean evaluation
        try {
            bool booleanResult = parsedExpression->evaluate_boolean();
            cout << (booleanResult ? "true" : "false") << endl;
        } catch (exception) {
            // if boolean evaluation fails, tries integer evaluation
            int intResult = parsedExpression->evaluate();
            cout << intResult << endl;
        }

        // free tree
        delete parsedExpression;
    } catch (exception) {
        cout << "error" << endl;
    }
}

int main() {
    unsigned int n; 
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string expr;
        getline(cin, expr);

        test_expression(expr);
    }

    return 0;
}
