#ifndef OPERAND_H
#define OPERAND_H

#include <string>
using namespace std;

class Operand {
    private:
        string operand;
    
    public:
        Operand(string operand);
        float resolve(float left, float right);
        float resolve(float expression);
};

#endif