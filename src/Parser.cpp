#include "../include/Parser.h"
#include "../include/expressions/Expression.h"
#include "../include/expressions/LiteralExpression.h"
#include "../include/expressions/BinaryExpression.h"
#include "../include/expressions/UnaryExpression.h"
#include "../include/Operand.h"

#include <bits/stdc++.h>
using namespace std;

Parser::Parser(const string expr): str_expression(expr), pos(0) {};

inline void Parser::skipWhitespace() {
    while (pos < str_expression.length() && isspace(str_expression[pos])) {
        pos++;
    }
}

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

        // recursively parse the next expression
        Expression* expression = parse_unary_exp();
        return new UnaryExpression(expression, operand);
    }

    // if not a unary operator, parse as primary expression
    return parse_primary_exp();
}

Expression* Parser::parse_primary_exp() {
    skipWhitespace();

    if (str_expression[pos] == '(') {

        pos++;

        Expression* expression = parse_exp();

        if (pos >= str_expression.length() || str_expression[pos] != ')') {
            throw invalid_argument("Expected ')'");
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

        // decides which path evaluation (integer/boolean) to take
        if (literal == "true") return new LiteralExpression(true);
        else if (literal == "false") return new LiteralExpression(false);
        else return new LiteralExpression(stoi(literal));
    }
}