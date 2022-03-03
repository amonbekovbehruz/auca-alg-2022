#pragma once

#include <cstddef>
#include <string>
#include <sstream>

template <typename T>
class List
{
    struct Link
    {
        Link *mPrev;
        Link *mNext;

        Link(Link *prev, Link *next) : mPrev(prev), mNext(next) {}
    };

    struct Node : Link
    {
        int mData;
        Node(int data, Link *prev, Link *next) : Link(prev, next), mData(data) {}
    };

    Link mAnchor;
    std::size_t mSize;

public:
    List() : mAnchor(&mAnchor, &mAnchor), mSize(0) {}

    size_t size() const
    {
        return mSize;
    }

    void pushBack(T x)
    {
        mAnchor.mPrev = mAnchor.mPrev->mNext = new Node(x, mAnchor.mPrev, &mAnchor);
        ++mSize;
    }

    string toStr() const
    {
        std::ostringstream sout;
        return sout.str();
    }
};