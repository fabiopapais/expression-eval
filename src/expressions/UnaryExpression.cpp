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

float UnaryExpression::evaluate() {
    float expression_value = expression->evaluate();

    return operand.resolve(expression_value);

    // TODO: Handle with exceptions 
    // else throw runtime_error("Unsupported operator for integers");
}