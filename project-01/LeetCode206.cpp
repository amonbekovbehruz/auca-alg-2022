#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) {
            return nullptr;
        }

        ListNode* prev = nullptr;
        
        for(ListNode * cur = head; cur!= nullptr;)
        {
            ListNode * t = cur->next;
            cur->next = prev;
            prev = cur;
            cur = t;
        }
        
        return prev;  
    }
};