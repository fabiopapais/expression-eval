#include "../include/Operand.h"
#include <bits/stdc++.h>

using namespace std;

Operand::Operand(string operand) {
    static const set<string> accepted_values = {"+", "-", "*", "/", "||", "&&", 
                                                "==", "!=", "<", ">", "<=", ">="};
    
    if (accepted_values.find(operand) == accepted_values.end()) {
        throw invalid_argument("Invalid operand");
    }

    this->operand = operand;
};

int Operand::resolve(int left, int right) {
    if (operand == "+") return left + right;
    else if (operand == "-") return left - right;
    else if (operand == "*") return left * right;
    else if (operand == "/") {
        if (right == 0) {
            throw invalid_argument("Division by zero");
        }
        return left / right;
    }
    else if (operand == "||") return left || right;
    else if (operand == "&&") return left && right;
    else if (operand == "==") return left == right;
    else if (operand == "!=") return left != right;
    else if (operand == "<") return left < right;
    else if (operand == ">") return left > right;
    else if (operand == "<=") return left <= right;
    else if (operand == ">=") return left >= right;
};

int Operand::resolve(int expression) {
    if (operand == "+") return +expression;
    else if (operand == "-") return -expression;
};

bool Operand::resolve(bool left, bool right) {
    if (operand == "||") return left || right;
    else if (operand == "&&") return left && right;
    else if (operand == "==") return left == right;
    else if (operand == "!=") return left != right;
};
