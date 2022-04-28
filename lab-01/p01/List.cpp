#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node* mPrev;
    Node* mNext;
    int mData;

    Node(Node* prev, Node* next, int data) :mPrev(prev), mNext(next), mData(data) {}
};

void printInDirectOrder(Node *head) {
    for(Node *p = head; p != nullptr; p->mNext) {
        cout << p->mData << " ";
    } 
    cout << endl;
}

void printInReverseOrder(Node *tail) {
    for(Node *p = tail; p != nullptr; p->mPrev) {
        cout << p->mData << " ";
    }
    cout << endl;
}

void pushBack(Node *head, Node *tail, int elem) {
    if(head = nullptr) {
        head = tail = new Node(nullptr, nullptr, elem);
    } else {
        tail->mNext = new Node(tail, nullptr, elem);
        tail = tail->mNext;
    }
}

void insertBefore(Node *head, Node *curr, int elem) {
    if(head == curr) {
        head->mPrev = new Node(nullptr, head, elem);
        head = head->mPrev;
    } else {
        Node *temp = new Node(curr->mPrev, curr, elem);
        temp->mPrev->mNext = temp;
        curr->mPrev = temp;
    }
}

Node *erase(Node *head, Node *tail, Node *curr) {
    if(head == tail) {
        delete curr;
        head = tail = nullptr;
        return nullptr;
    } 

    if(head == curr) {
        head->mNext->mPrev = nullptr;
        head = head->mNext;
        delete curr;
        return head;
    } 

    if(tail == curr) {
        tail->mPrev->mNext = nullptr;
        tail = tail->mPrev;
        delete curr;
        return nullptr;
    }

    curr->mPrev->mNext = curr->mNext;
    curr->mNext->mPrev = curr->mPrev;

    Node *temp = curr->mNext;
    delete curr;
    return temp;
}