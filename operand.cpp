#include "operand.hpp"

Operand::Operand() {
    this->num = "";
}

Operand::Operand(std::string num) {
    this->num = num;
}

bool Operand::IsNegative() {
    if(this->num[0] == '-') {
        return true;
    }
    return false;
}

std::string Operand::GetValue() {
    return this->num;
}

int Operand::GetNumberOfDigits() {
    return this->num.length();
}

void Operand::Pad(int padNum) {
    this->num.insert(this->num.begin(), padNum, '0');
}

void Operand::SetValue(std::string valueToSet) {
    this->num = valueToSet;
}

void Operand::FlipSign() {
    this->num.erase(0,1);
}