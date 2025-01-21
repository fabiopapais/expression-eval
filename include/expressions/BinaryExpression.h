#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "Expression.h"
#include "../Operand.h"

class BinaryExpression : public Expression {
    private:
        Expression* left;
        Expression* right;
        Operand operand;
    
    public:
        BinaryExpression(Expression* left, Operand operand, Expression* right);
        ~BinaryExpression();

        float evaluate() override;
};


#endif