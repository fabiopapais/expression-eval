#ifndef OPERAND_H
#define OPERAND_H

#include <string>
using namespace std;

class Operand {
    private:
        string operand;
    
    public:
        Operand(string operand);
        // For integers
        int resolve(int left, int right);
        int resolve(int expression);
        // For booleans
        bool resolve(bool left, bool right);
};

#endif