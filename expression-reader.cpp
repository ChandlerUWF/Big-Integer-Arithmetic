#include "expression-reader.hpp"

ExpressionReader::ExpressionReader(std::string fileName) {
    this->fileName = fileName;
}

bool ExpressionReader::ReadNextExpression() {
    std::ifstream fileInput(fileName);
    
    if(!fileInput) {
        return false;
    }
    if(fileInput.eof()) {
        return false;
    }

    std::string num1;
    std::string num2;
    char sign;
    int j = 0;

    fileInput >> num1;
    fileInput >> sign;
    fileInput >> num2;

    while(j != i) {
        j += 1;
        if(j == i) {
            fileInput >> num1;
            fileInput >> sign;
            fileInput >> num2;
            break;
        }
        fileInput >> num1;
        fileInput >> sign;
        fileInput >> num2;
    }

    if(fileInput.eof()) {
        return false;
    }
    
    this->i += 1;
    ae = new ArithmeticExpression(num1, num2, sign);
    return true;
}

std::string ExpressionReader::ShowResult() {
    BigIntegerArithmetic bia(ae);
    return bia.ShowResults();
}