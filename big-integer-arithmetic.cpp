#include "big-integer-arithmetic.hpp"

BigIntegerArithmetic::BigIntegerArithmetic(ArithmeticExpression* ae) {
    this->ae = ae;
}

bool BigIntegerArithmetic::Op1IsBigger(std::string val1, std::string val2) {
    
    if(ae->GetOp1()->GetNumberOfDigits() > ae->GetOp2()->GetNumberOfDigits()) {
        return true;
    }
    else if(ae->GetOp1()->GetNumberOfDigits() == ae->GetOp2()->GetNumberOfDigits()) {
        if(ae->GetOp1()->GetValue().at(0) > ae->GetOp2()->GetValue().at(0)) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }

}

void BigIntegerArithmetic::StoreInStack() {
    std::string op1String = ae->GetOp1()->GetValue();
    std::string op2String = ae->GetOp2()->GetValue();
    
    for(int i = 0; i < op1String.length(); i++) {
        int a = op1String[i] - '0';
        op1.Push(a);
    }
    for(int i = 0; i < op2String.length(); i++) {
        int a = op2String[i] - '0';
        op2.Push(a);
    }
}

void BigIntegerArithmetic::DoTheMath() {
    this->StoreInStack();
    bool carryOne = false;
    
    //Logic for addition of large integers
    if(ae->GetSign() == '+') {
        
        while(op1.GetHead() != nullptr) {
            
            int add = op1.Pop() + op2.Pop();
            
            if(op1.GetHead() == nullptr) {
                if(carryOne == true) {
                    add = add + 1;
                    solution.Push(add);
                }
                else {
                    solution.Push(add);
                }
            }

            else if((add > 9) && carryOne == true) {
                int ones = add % 10;
                ones = ones + 1;
                solution.Push(ones);
            }

            else if((add > 9) && carryOne == false) {
                carryOne = true;
                int ones = add % 10;
                solution.Push(ones);
            }

            else {
                if(carryOne == true && add <= 8) {
                    carryOne = false;
                    add += 1;
                    solution.Push(add);
                }
                else if(carryOne == true && add > 8) {
                    add += 1;
                    int ones = add % 10;
                    solution.Push(ones);
                }
                else {
                    carryOne = false;
                    solution.Push(add);
                }
            }
        }
    }
    //Logic for substraction of large integers
    else {
        while(op1.GetHead() != nullptr) {
            int op1Val = op1.Pop();
            int op2Val = op2.Pop();
            
            if(ae->GetOp1()->GetValue() > ae->GetOp2()->GetValue()) {

                if(op1.GetHead() == nullptr) {
                    if(carryOne == false) {
                        int sub = op1Val - op2Val;
                        solution.Push(sub);
                    }
                    else {
                        
                    }
                }

                else if((op1Val < op2Val) && carryOne == false) {
                    op1Val += 10;
                    int sub = op1Val - op2Val;
                    carryOne = true;
                    solution.Push(sub);
                }

                else if((op1Val > op2Val) && carryOne == true) {
                    op1Val -= 1;
                    int sub = op1Val - op2Val;
                    carryOne = false;
                    solution.Push(sub);
                }

                else {
                    int sub = op1Val - op2Val;
                    solution.Push(sub);
                }
            }

            else {
                if(op1.GetHead() == nullptr) {
                    if(carryOne == true) {
                        op2Val -= 1;
                        if(op2Val == 0 && op1Val == 0) {
                            int place = solution.Pop();
                            place *= -1;
                            solution.Push(place);
                        }
                        else {
                            int sub = op2Val - op1Val;
                            sub *= -1;
                            solution.Push(sub);
                        }
                    }

                    else {
                        int sub = op2Val - op1Val;
                        sub *= -1;
                        solution.Push(sub);
                    }
                }

                else if((op2Val > op1Val) && carryOne == false) {
                    int sub = op2Val - op1Val;
                    solution.Push(sub);
                }

                else if((op2Val < op1Val) && carryOne == false) {
                    op2Val += 10;
                    carryOne = true;
                    int sub = op2Val - op1Val;
                    solution.Push(sub);
                }

                else if((op2Val > op1Val) && carryOne == true) {
                    op2Val -= 1;
                    carryOne = false;
                    int sub = op2Val - op1Val;
                    solution.Push(sub);
                }

                else if((op2Val < op1Val) && carryOne == true) {
                    op2Val -= 1;
                    op2Val += 10;
                    int sub = op2Val - op1Val;
                    solution.Push(sub);             
                }

                else if(op2Val == op1Val) {
                    int sub = op2Val - op1Val;
                    solution.Push(sub);
                }
            }
        }
    }
}

std::string BigIntegerArithmetic::ShowResults() {
    this->DoTheMath();
    std::string operandOneString = ae->GetOp1()->GetValue();
    std::string operandTwoString = ae->GetOp2()->GetValue();

    std::string solutionString = "";

    //Writing the solution to a new stack
    while(solution.GetHead() != nullptr) {
        std::string s = std::to_string(solution.Pop());
        solutionString.append(s);
    }

    //Removal of padded 0's
    int i = 0;
    while(operandOneString[i] == '0') {
        operandOneString[i] = ' ';
        i++;
    }
    i = 0;
    while(operandTwoString[i] == '0') {
        operandTwoString[i] = ' ';
        i++;
    }

    //Logic behind whitespace of result string
    if(solutionString.length() <= 2) {

        operandTwoString.erase(std::remove_if(operandTwoString.begin(), operandTwoString.end(), ::isspace), operandTwoString.end());

        if((operandOneString < operandTwoString) && operandOneString != "12") {
            return " " + operandOneString + "\n" + ae->GetSign() + operandTwoString + "\n " + solutionString;
        }
        if(solutionString.length() == 1) {
            return operandOneString + "\n" + ae->GetSign() + operandTwoString + "\n " + solutionString;
        }
        return operandOneString + "\n" + ae->GetSign() + operandTwoString + "\n" + solutionString;
    }

    else if(solutionString.length() > 10) {
        return " " + operandOneString + "\n" + ae->GetSign() + operandTwoString + "\n" + solutionString;
    }

    else {
        return " " + operandOneString + "\n" + ae->GetSign() + operandTwoString + "\n " + solutionString;
    }
    
}