#ifndef BIGINTEGERARITHMETIC_HPP
#define BIGINTEGERARITHMETIC_HPP

#include "arithmetic-expression.hpp"
#include <cctype>
#include <algorithm>

class BigIntegerArithmetic {
    private:
        ArithmeticExpression* ae;
        Stack op1;
        Stack op2;
        Stack solution;
    public:
        BigIntegerArithmetic(ArithmeticExpression* ae);
        bool Op1IsBigger(std::string val1, std::string val2);
        void StoreInStack();
        void DoTheMath();
        std::string ShowResults();
};

#endif