#include "node.hpp"

Node::Node(int val, Node* next) {
    this->val = val;
    this->next = next;
}

int Node::GetValue() {
    return this->val;
}

Node* Node::GetNext() {
    return this->next;
}

void Node::SetNext(Node* next) {
    this->next = next;
}