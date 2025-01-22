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

int BinaryExpression::evaluate() {
    int left_value = left->evaluate();
    int right_value = right->evaluate();

    return operand.resolve(left_value, right_value);

    // TODO: Handle with exceptions
}

bool BinaryExpression::evaluate_boolean() {
    bool left_value = left->evaluate_boolean();
    bool right_value = right->evaluate_boolean();

    return operand.resolve(left_value, right_value);

    // TODO: Handle with exceptions
}