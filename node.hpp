class Node {
    private:
        int val;
        Node* next;
    public:
        Node(int val, Node* next = nullptr);
        int GetValue();
        Node* GetNext();
        void SetNext(Node* next);
};