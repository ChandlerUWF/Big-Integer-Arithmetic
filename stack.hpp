#include "node.hpp"
#include <limits>

class Stack {
    private:
        Node* head;
    public:
        Stack();
        ~Stack();
        void Push(int data);
        bool IsEmpty();
        int Pop();
        Node* GetHead();
};