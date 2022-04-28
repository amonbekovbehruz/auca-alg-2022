#include "HashSetStr.hpp"

#include <iostream>

HashSetStr::~HashSetStr()
{
    for (std::size_t i = 0; i < mBuckets.size(); i++)
    {
        for (Node *p = mBuckets[i]; p != nullptr;)
        {
            Node *t = p;
            p = p->mNext;
            delete t;
        }
    }
}

// bool HashSetStr::insert(const std::string &key)
// {
//     std::size_t index = defaultHashFunc(key) % mBuckets.size();

//     for (Node *p = mBuckets[index]; p != nullptr; p = p->mNext)
//     {
//         if (p->mData == key)
//         {
//             return false;
//         }
//     }

//     if (mSize == mBuckets.size())
//     {
//         rehash();
//         index = defaultHashFunc(key) % mBuckets.size();
//     }

//     mBuckets[index] = new Node(key, mBuckets[index]);
//     ++mSize;

//     return true;
// }

bool HashSetStr::insert(const std::string &key) {
    std::size_t index = defaultHashFunc(key) % mBuckets.size();
    for(Node *p = mBuckets[index]; p != nullptr; p = p->mNext) {
        if(p->mData == key) {
            return false;
        }
    }

    if(mSize == mBuckets.size()) {
        rehash();
        index = defaultHashFunc(key) % mBuckets.size();
    }

    mBuckets[index] = new Node(key, mBuckets[index]);
    ++mSize;

    return true;
}

// bool HashSetStr::find(const std::string &key) const
// {
//     std::size_t index = defaultHashFunc(key) % mBuckets.size();

//     for (Node *p = mBuckets[index]; p != nullptr; p = p->mNext)
//     {
//         if (p->mData == key)
//         {
//             return true;
//         }
//     }

//     return false;
// }

bool HashSetStr::find(const std::string &key) const {
    std::size_t index = defaultHashFunc(key) % mBuckets.size();

    for(Node *p = mBuckets[index]; p != nullptr; p = p->mNext) {
        if(p->mData == key) {
            return true;
        }
    }

    return false;
}

// void HashSetStr::print() const
// {
//     for (std::size_t i = 0; i < mBuckets.size(); i++)
//     {
//         for (Node *p = mBuckets[i]; p != nullptr; p = p->mNext)
//         {
//             std::cout << " " << p->mData;
//         }
//         std::cout << "\n";
//     }
// }

void HashSetStr::print() const {
    for(std::size_t i = 0; i < mBuckets.size(); i++) {
        for(Node *p = mBuckets[i]; p != nullptr; p = p->mNext) {
            std::cout << p->mData << " ";
        }
        std::cout << "\n";
    }
}

// bool HashSetStr::erase(const std::string &key)
// {
//     std::size_t index = defaultHashFunc(key) % mBuckets.size();

//     for (Node *curr = mBuckets[index], *prev = nullptr; curr != nullptr; curr = curr->mNext)
//     {
//         if (curr->mData == key)
//         {
//             if (prev == nullptr)
//             {
//                 mBuckets[index] = curr->mNext;
//             }
//             else
//             {
//                 prev->mNext = curr->mNext;
//             }
//             delete curr;

//             --mSize;
//             return true;
//         }
//         prev = curr;
//     }

//     return false;
// }

bool HashSetStr::erase(const std::string &key) {
    std::size_t index = defaultHashFunc(key) % mBuckets.size();
    for(Node *curr = mBuckets[index], *prev = nullptr; curr != nullptr; curr = curr->mNext) {
        if(curr->mData == key) {
            if(prev == nullptr) {
                mBuckets[index] = curr->mNext;
            } else {
                prev->mNext = curr->mNext;
            }

            delete curr;
            --mSize;

            return true;
        }

        prev = curr;
    }

    return false;
}

std::size_t HashSetStr::defaultHashFunc(const std::string &key)
{
    std::size_t res = 0;

    for (auto ch : key)
    {
        res += 97 * ch + 31;
        res *= 2;
    }

    return res;
}

void HashSetStr::rehash()
{
    std::vector<Node *> newBuckets(2 * mBuckets.size() + 1);

    for (std::size_t i = 0; i < mBuckets.size(); i++)
    {
        for (Node *curr = mBuckets[i]; curr != nullptr;)
        {
            std::size_t index = defaultHashFunc(curr->mData) % newBuckets.size();

            Node *temp = curr->mNext;

            curr->mNext = newBuckets[index];
            newBuckets[index] = curr;

            curr = temp;
        }
    }
}