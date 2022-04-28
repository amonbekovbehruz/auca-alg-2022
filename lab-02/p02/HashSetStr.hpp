#pragma once

#include <vector>
#include <string>

class HashSetStr
{
    struct Node
    {
        std::string mData;
        Node *mNext;

        Node(std::string data, Node *next) : mData(data), mNext(next) {}
    };

    std::vector<Node *> mBuckets;
    std::size_t mSize;

    static std::size_t defaultHashFunc(const std::string &key);

    void rehash();

public:
    HashSetStr() : mBuckets(11), mSize(0)
    {
    }

    ~HashSetStr();

    std::size_t size() const
    {
        return mSize;
    }

    bool find(const std::string &key) const;
    bool insert(const std::string &key);
    void print() const;
    bool erase(const std::string &key);
};