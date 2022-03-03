#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Node
{
  int mData;
  Node *mPrev;
  Node *mNext;
  Node(int data, Node *prev, Node *next)
      : mData(data), mPrev(prev), mNext(next)
  {
  }
};

void printDirOrder(Node *head)
{
  for (Node *p = head; p != nullptr; p = p->mNext)
  {
    cout << p->mData << " ";
  }
  cout << endl;
}

void printRevOrder(Node *tail)
{
  for (Node *p = tail; p != nullptr; p = p->mPrev)
  {
    cout << p->mData << " ";
  }
  cout << endl;
}

void clear(Node *&head, Node *&tail)
{

  for (Node *p = head; p != nullptr;)
  {
    Node *t = p;
    p = p->mNext;
    delete t;
  }
  head = tail = nullptr;
}

void pushBack(Node *&head, Node *&tail, int x)
{
  if (head == nullptr)
  {
    head = tail = new Node(x, nullptr, nullptr);
  }
  else
  {
    tail->mNext = new Node(x, tail, nullptr);
    tail = tail->mNext;
  }
}
void insertBefore(Node *&head, Node *cur, int x)
{
  if (head == cur)
  {
    head->mPrev = new Node(x, nullptr, head);
    head = head->mPrev;
  }
  else
  {
    Node *t = new Node(x, cur->mPrev, cur);
    t->mPrev->mNext = t;
    cur->mPrev = t;
  }
}

Node *erase(Node *&head, Node *&tail, Node *cur)
{
  if (head == tail)
  {
    delete cur;
    head = tail = nullptr;
    return nullptr;
  }
  if (head == cur)
  {
    head->mNext->mPrev = nullptr;
    head = head->mNext;
    delete cur;
    return head;
  }
  if (tail == cur)
  {
    tail->mPrev->mNext = nullptr;
    tail = tail->mPrev;
    delete cur;
    return nullptr;
  }

  cur->mNext->mPrev = cur->mPrev;
  cur->mPrev->mNext = cur->mNext;

  Node *t = cur->mNext;
  delete cur;
  return  t;
}
int main()
{
  Node *head = nullptr;
  Node *tail = nullptr;

  for (int x; cin >> x;)
  {
    pushBack(head, tail, x);
  }
  printDirOrder(head);
  printRevOrder(tail);

  for (Node *p = head; p != nullptr; p = p->mNext)
  {
    if (p->mData % 2 == 0)
    {
      insertBefore(head, p, 0);
    }
  }

  for (Node *p = head; p != nullptr; p = p->mNext)
  {
    if (p->mData % 2 == 0)
    {
      p = erase(head, tail, p);
    }
    else
    {
      p = p->mNext;
    }
  }

  printDirOrder(head);
  printRevOrder(tail);

  clear(head, tail);
}
