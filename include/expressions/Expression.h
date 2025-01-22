#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression {
    public:
        virtual int evaluate();
        virtual bool evaluate_boolean();
};

#endif