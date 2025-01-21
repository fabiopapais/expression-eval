#ifndef PARSER_H
#define PARSER_H

#include "expressions/Expression.h"
#include "expressions/LiteralExpression.h"
#include "expressions/BinaryExpression.h"
#include "expressions/UnaryExpression.h"

#include <bits/stdc++.h>
using namespace std;

class Parser {
private:
    string str_expression;
    int pos;
    
    void skipWhitespace();
    
    Expression* parse_exp();
    Expression* parse_or_exp();
    Expression* parse_and_exp();
    Expression* parse_eq_exp();
    Expression* parse_rel_exp();
    Expression* parse_add_exp();
    Expression* parse_mul_exp();
    Expression* parse_unary_exp();
    Expression* parse_primary_exp();

    int string_to_int(string str);

public:
    Parser(const string expr);
    Expression* parse();
};

#endif