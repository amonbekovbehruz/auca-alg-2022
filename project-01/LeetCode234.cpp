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
    bool isPalindrome(ListNode* head) {
        vector<ListNode*> list;
        ListNode *curr = head;
        while(curr != nullptr) {
            list.push_back(curr);
            curr = curr->next;
        }

        for (int i = 0; i < list.size()/2; i++)
        {
            auto it = list.begin();
            auto rit = list.rbegin();

            if(*it != *rit) {
                false;
            }

            it++;
            rit++;
        }

        return true;
    }
};