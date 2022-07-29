#ifndef EXPRESSIONREADER_HPP
#define EXPRESSIONREADER_HPP

#include "big-integer-arithmetic.hpp"
#include <fstream>
#include <vector>

class ExpressionReader{
    private:
        std::string fileName;
        ArithmeticExpression * ae;
        int i = 0;
    public:
        ExpressionReader();
        ExpressionReader(std::string fileName);
        bool ReadNextExpression();
        std::string ShowResult();
};

#endif