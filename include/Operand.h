#ifndef OPERAND_H
#define OPERAND_H

#include <string>
using namespace std;

class Operand {
    private:
        string operand;
    
    public:
        Operand(string operand);
        // for integers
        int resolve(int left, int right);
        int resolve(int expression);
        // for booleans
        bool resolve(bool left, bool right);

        string get_operand();
};

#endif