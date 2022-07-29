#include "arithmetic-expression.hpp"

ArithmeticExpression::ArithmeticExpression(std::string val1, std::string val2, char sign) {
    this->o1.SetValue(val1);
    this->o2.SetValue(val2);
    this->sign = sign;

    if(o2.IsNegative() && sign == '+') {
        o2.FlipSign();
        this->sign = '-';
    }

    if(o2.IsNegative() && sign == '-') {
        o2.FlipSign();
        this->sign = '+';
    }

    if(o1.GetNumberOfDigits() > o2.GetNumberOfDigits()) {
        int padNum = o1.GetNumberOfDigits() - o2.GetNumberOfDigits();
        o2.Pad(padNum);
    }
    else {
        int padNum = o2.GetNumberOfDigits() - o1.GetNumberOfDigits();
        o1.Pad(padNum);
    }

    this->val1 = o1.GetValue();
    this->val2 = o2.GetValue();
}

std::ostringstream& operator<<(std::ostringstream& os, const ArithmeticExpression& obj) {
    os << obj.val1 << " " << obj.val2 << " " << obj.sign;
    return os;
}

Operand* ArithmeticExpression::GetOp1() {
    Operand* opPtr = new Operand(this->val1);
    return opPtr;
}

Operand* ArithmeticExpression::GetOp2() {
    Operand* opPtr = new Operand(this->val2);
    return opPtr;
}

char ArithmeticExpression::GetSign() {
    return this->sign;
}
