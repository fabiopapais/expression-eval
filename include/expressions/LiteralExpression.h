#ifndef LITERALEXPRESSION_H
#define LITERALEXPRESSION_H

#include "Expression.h"

#include <string>

class LiteralExpression : public Expression {
    private:
        enum class Type {
            INT,
            BOOLEAN
        };

        Type type;

        int value;
        bool boolean_value;

    public:
        LiteralExpression(int value);
        LiteralExpression(bool value);
        int evaluate() override;
        bool evaluate_boolean() override;
};

#endif