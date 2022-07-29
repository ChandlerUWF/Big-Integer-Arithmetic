#ifndef OPERAND_HPP
#define OPERAND_HPP

#include <string>
#include "stack.hpp"

class Operand {
    private:
        std::string num;
    public:
        Operand();
        Operand(std::string num);
        bool IsNegative();
        std::string GetValue();
        int GetNumberOfDigits();
        void Pad(int padNum);
        void SetValue(std::string valueToSet);
        void FlipSign();
};

#endif