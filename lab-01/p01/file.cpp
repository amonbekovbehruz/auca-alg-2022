#include <iostream>

struct Node{
    int mData;
    Node *mPrev;
    Node *mNext;
    Node(int data, Node *prev, Node *next)
    :mData(data), mPrev(prev), mNext(next) {

    }
};

void printInDirectOrder(Node *head) {
    for (Node *p = head; p != nullptr; p = p->mNext) 
    {
        std::cout << p->mData << " ";
    } 
    std::cout << '\n';
}

void printInReverseOrder(Node *tail) {
    for (Node *p = tail; p != nullptr; p = p->mPrev) 
    {
        std::cout << p->mData << " ";
    } 
    std::cout << '\n';
}

int main() {
    Node *p01 = new Node(1, nullptr, nullptr);
    Node *p02 = new Node(2, nullptr, nullptr);
    Node *p03 = new Node(3, nullptr, nullptr);

    for (Node *p = p01; p != nullptr; p = p->mNext) 
    {
        std::cout << p->mData << " ";
    } 
    std::cout << '\n';
}