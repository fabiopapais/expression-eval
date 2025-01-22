#include "../../include/expressions/UnaryExpression.h"
#include "../../include/Operand.h"

#include <bits/stdc++.h>
using namespace std;

UnaryExpression::UnaryExpression(Expression* expression, Operand operand): 
    expression(expression), 
    operand(operand) {};

UnaryExpression::~UnaryExpression() {
    delete expression;
}

int UnaryExpression::evaluate() {
    int expression_value = expression->evaluate();

    return operand.resolve(expression_value);

    // TODO: Handle with exceptions 
    // else throw runtime_error("Unsupported operator for integers");
}

bool UnaryExpression::evaluate_boolean() {
    bool expression_value = expression->evaluate_boolean();

    return operand.resolve(expression_value);

    // TODO: Handle with exceptions 
    // else throw runtime_error("Unsupported operator for integers");
}