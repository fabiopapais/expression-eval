#ifndef LITERALEXPRESSION_H
#define LITERALEXPRESSION_H

#include "Expression.h"

class LiteralExpression : public Expression {
    private:
        int value;

    public:
        LiteralExpression(int value);
        int evaluate() override;
};

#endif