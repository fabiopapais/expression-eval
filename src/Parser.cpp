#include "../include/Parser.h"
#include "../include/expressions/Expression.h"
#include "../include/expressions/LiteralExpression.h"
#include "../include/expressions/BinaryExpression.h"
#include "../include/expressions/UnaryExpression.h"
#include "../include/Operand.h"

#include <bits/stdc++.h>
using namespace std;

void Parser::skipWhitespace() {
    while (pos < str_expression.length() && isspace(str_expression[pos])) {
        pos++;
    }
}

Parser::Parser(const string expr): str_expression(expr), pos(0) {};

Expression* Parser::parse() {
    return parse_exp();
}

Expression* Parser::parse_exp() {
    return parse_or_exp();
}

Expression* Parser::parse_or_exp() {
    Expression* left = parse_and_exp();

    skipWhitespace();

    if (str_expression[pos] == '|') {
        Operand operand = Operand("||");

        pos++;
        pos++;

        Expression* right = parse_and_exp();

        return new BinaryExpression(left, operand, right);
    }

    return left;
}

Expression* Parser::parse_and_exp() {
    Expression* left = parse_eq_exp();

    skipWhitespace();

    if (str_expression[pos] == '&') {
        Operand operand = Operand("&&");

        pos++;
        pos++;

        Expression* right = parse_eq_exp();

        return new BinaryExpression(left, operand, right);
    }

    return left;
}

Expression* Parser::parse_eq_exp() {
    Expression* left = parse_rel_exp();

    skipWhitespace();

    if (str_expression[pos] == '=') {
        Operand operand = Operand("==");

        pos++;
        pos++;

        Expression* right = parse_rel_exp();

        return new BinaryExpression(left, operand, right);
    }

    else if (str_expression[pos] == '!') {
        Operand operand = Operand("!=");

        pos++;
        pos++;

        Expression* right = parse_rel_exp();

        return new BinaryExpression(left, operand, right);
    }

    return left;
}

Expression* Parser::parse_rel_exp() {
    Expression* left = parse_add_exp();

    skipWhitespace();

    if (str_expression[pos] == '<') {
        if (str_expression[pos + 1] == '=') {
            Operand operand = Operand("<=");

            pos++;
            pos++;

            Expression* right = parse_add_exp();

            return new BinaryExpression(left, operand, right);
        }

        Operand operand = Operand("<");

        pos++;
        pos++;

        Expression* right = parse_add_exp();

        return new BinaryExpression(left, operand, right);
    }

    else if (str_expression[pos] == '>') {
        if (str_expression[pos + 1] == '=') {
            Operand operand = Operand(">=");

            pos++;
            pos++;

            Expression* right = parse_add_exp();

            return new BinaryExpression(left, operand, right);
        }

        Operand operand = Operand(">");

        pos++;
        pos++;

        Expression* right = parse_add_exp();

        return new BinaryExpression(left, operand, right);
    }

    return left;
}

Expression* Parser::parse_add_exp() {
    Expression* left = parse_mul_exp();

    skipWhitespace();

    if (str_expression[pos] == '+') {
        Operand operand = Operand("+");

        pos++;

        Expression* right = parse_mul_exp();

        return new BinaryExpression(left, operand, right);
    }

    else if (str_expression[pos] == '-') {
        Operand operand = Operand("-");

        pos++;

        Expression* right = parse_mul_exp();

        return new BinaryExpression(left, operand, right);
    }

    return left;
}

Expression* Parser::parse_mul_exp() {
    Expression* left = parse_unary_exp();

    skipWhitespace();

    if (str_expression[pos] == '*') {
        Operand operand = Operand("*");

        pos++;

        Expression* right = parse_unary_exp();

        return new BinaryExpression(left, operand, right);
    }

    else if (str_expression[pos] == '/') {
        Operand operand = Operand("/");

        pos++;

        Expression* right = parse_unary_exp();

        return new BinaryExpression(left, operand, right);
    }

    return left;
}

Expression* Parser::parse_unary_exp() {
    skipWhitespace();

    if (str_expression[pos] == '+' || str_expression[pos] == '-') {
        Operand operand = Operand(string(1, str_expression[pos]));

        pos++;

        Expression* expression = parse_primary_exp();

        return new UnaryExpression(expression, operand);
    }

    return parse_primary_exp();
}

Expression* Parser::parse_primary_exp() {
    skipWhitespace();

    if (str_expression[pos] == '(') {

        pos++;

        Expression* expression = parse_exp();

        if (pos >= str_expression.length() || str_expression[pos] != ')') {
            cout << "error: expected ')'" << endl;
            // TODO: Handle with exceptions
        }
        pos++; // consumes ')'

        return expression;
    }

    else {
        string literal = "";

        // looks for numbers or booleans ("true" or "false")
        while (pos < str_expression.length() && isalnum(str_expression[pos])) {
            literal += str_expression[pos];
            pos++;
        }

        float int_literal = string_to_float(literal);

        return new LiteralExpression(int_literal);
    }
}

float Parser::string_to_float(string str) {
    if (str == "true") {
        return 1.0;
    } else if (str == "false") {
        return 0.0;
    } else {
        return stof(str); // Parse as an integer
    }
}