#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "Expression.h"
#include "../Operand.h"

class UnaryExpression : public Expression {
    private:
        Expression* expression;
        Operand operand;
    
    public:
        UnaryExpression(Expression* expression, Operand operand);
        ~UnaryExpression();

        float evaluate() override;
};


#endif