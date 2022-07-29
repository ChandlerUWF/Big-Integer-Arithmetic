#include "expression-reader.hpp"
#include <iostream>

int main() {
    ExpressionReader er("expressions.txt");

    while(er.ReadNextExpression() == true) {
        std::cout << er.ShowResult();
        std::cout << "\n";
        std::cout << "----------" << std::endl;
    }
}