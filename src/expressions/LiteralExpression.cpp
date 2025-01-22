#include "../../include/expressions/LiteralExpression.h"

#include <bits/stdc++.h>
using namespace std;

LiteralExpression::LiteralExpression(int value): 
    value(value), type(Type::INT) {};

LiteralExpression::LiteralExpression(bool boolean_value): 
    boolean_value(boolean_value), type(Type::BOOLEAN) {};

int LiteralExpression::evaluate() {
    if (type != Type::INT) {
        throw std::runtime_error("Type is not INT");
    }
    return value;
}

bool LiteralExpression::evaluate_boolean() {
     if (type != Type::BOOLEAN) {
        throw std::runtime_error("Type is not BOOLEAN");
    }
    return boolean_value;
}