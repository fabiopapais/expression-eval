#include "../include/Operand.h"
#include <bits/stdc++.h>

using namespace std;

Operand::Operand(string operand) {
    static const set<string> accepted_values = {"+", "-", "*", "/", "||", "&&", 
                                                "==", "!=", "<", ">", "<=", ">="};
    
    if (accepted_values.find(operand) == accepted_values.end()) {
        cout << "error" << endl;
        // TODO: handle exceptions  
        // throw invalid_argument("Invalid operand");
    }

    this->operand = operand;
};

float Operand::resolve(float left, float right) {
    if (operand == "+") return left + right;
    else if (operand == "-") return left - right;
    else if (operand == "*") return left * right;
    else if (operand == "/") return left / right;
    else if (operand == "||") return left || right;
    else if (operand == "&&") return left && right;
    else if (operand == "==") return left == right;
    else if (operand == "!=") return left != right;
    else if (operand == "<") return left < right;
    else if (operand == ">") return left > right;
    else if (operand == "<=") return left <= right;
    else if (operand == ">=") return left >= right;
};

float Operand::resolve(float expression) {
    if (operand == "+") return +expression;
    else if (operand == "-") return -expression;
};
