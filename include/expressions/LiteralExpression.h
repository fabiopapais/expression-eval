#ifndef LITERALEXPRESSION_H
#define LITERALEXPRESSION_H

#include "Expression.h"

class LiteralExpression : public Expression {
    private:
        float value;

    public:
        LiteralExpression(float value);
        float evaluate() override;
};

#endif