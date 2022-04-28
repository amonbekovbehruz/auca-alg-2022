#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct Node {
    Node *mPrev;
    Node *mNext;
    int mData;

    Node(Node *prev, Node *next, int data) : mPrev(prev), mNext(next), mData(data) {} 
};

void insertBefore(Node *&head, Node *curr, int data) {
    if (curr == head)
    {
        head->mPrev = new Node (nullptr, nullptr, data);
        head = head->mPrev;
    } else {
        curr->mPrev = new Node()
    } 
        
}

void pushBack(Node *head, Node *tail, int data) {
    if(head == nullptr) {
        head = tail = new Node(nullptr, nullptr, data);
    } else {
        tail->mNext = new Node(tail, nullptr, data);
        tail = tail->mNext;
    }
}

void printInDirectOrder(const list<int> &lst)
{
    for (auto e : lst)
    {
        cout << e << " ";
    }
    cout << endl;

    // what actually happens
    for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void printReverseOrder(const list<int> &lst)
{
    for (auto it = lst.rbegin(); it != lst.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    list<int> lst;

    for (int x; cin >> x;)
    {
        lst.push_back(x);
    }
    printInDirectOrder(lst);
    printReverseOrder(lst);

    for (auto p = lst.begin(); p != lst.end(); ++p)
    {
        if (*p % 2 == 0)
        {
            lst.insert(p, 0);
        }
    }
    printInDirectOrder(lst);
    printReverseOrder(lst);

    // for (auto p = lst.begin(); p != lst.end();)
    // {
    //     if (*p % 2 == 0)
    //     {
    //         p = lst.erase(p);
    //     }
    //     else
    //     {
    //         ++p;
    //     }
    // }

    lst.remove_if([](int e) {
        return e % 2 == 0;
    });

    printInDirectOrder(lst);
    printReverseOrder(lst);

    reverse(lst.begin(), lst.end());
}