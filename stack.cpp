#include "stack.hpp"

Stack::Stack() {
    this->head = nullptr;
}

void Stack::Push(int data) {
    Node* n = new Node(data, this->head);
    this->head = n;
}

bool Stack::IsEmpty() {
    if(this->head == nullptr) {
        return true;
    }
    return false;
}

int Stack::Pop() {
    if(this->IsEmpty()) {
        return std::numeric_limits<int>::min();
    }
    int popVal = head->GetValue();
    Node* garbage = this->head;
    this->head = this->head->GetNext();
    delete garbage;
    return popVal;
}

Stack::~Stack() {
    while(this->head != nullptr) {
        Node* m = head->GetNext();
        this->head = this->head->GetNext();
        delete m;
    }
}

Node* Stack::GetHead() {
    return this->head;
}