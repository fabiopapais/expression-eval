#include "../../include/expressions/LiteralExpression.h"

#include <bits/stdc++.h>
using namespace std;

LiteralExpression::LiteralExpression(int value): 
    value(value) {};

int LiteralExpression::evaluate() {
    return value;

    // TODO: Handle with exceptions 
    // else throw runtime_error("Unsupported operator for integers");
}