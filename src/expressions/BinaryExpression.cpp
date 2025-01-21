#include "../../include/expressions/BinaryExpression.h"
#include "../../include/Operand.h"

#include <bits/stdc++.h>
using namespace std;

BinaryExpression::BinaryExpression(Expression* left, Operand operand, Expression* right): 
    left(left), 
    operand(operand), 
    right(right) {};

BinaryExpression::~BinaryExpression() {
    delete left;
    delete right;
}

float BinaryExpression::evaluate() {
    float left_value = left->evaluate();
    float right_value = right->evaluate();

    return operand.resolve(left_value, right_value);

    // TODO: Handle with exceptions 
    // else throw runtime_error("Unsupported operator for integers");
}