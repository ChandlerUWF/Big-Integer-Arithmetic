#ifndef ARITHMETICEXPRESSION_HPP
#define ARITHMETICEXPRESSION_HPP

#include "operand.hpp"
#include <sstream>

class ArithmeticExpression {
    private:
        std::string val1;
        std::string val2;
        char sign;
        Operand o1;
        Operand o2;
    public:
        ArithmeticExpression(std::string val1, std::string val2, char sign);
        friend std::ostringstream& operator<<(std::ostringstream& os, const ArithmeticExpression& obj);
        Operand* GetOp1();
        Operand* GetOp2();
        char GetSign();
};

#endif