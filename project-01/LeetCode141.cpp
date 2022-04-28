#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        vector<ListNode*> vec;

        ListNode *curr = head;
        while (curr != nullptr)
         {
            for (int i = 0; i < vec.size(); i++)
            {
                if(vec[i] == curr) {
                    return true;
                }
            }

            if(curr == nullptr) {
                return false;
            }
            
            vec.push_back(curr);
            if (curr != nullptr) { curr = curr->next; }
        }
        
        return false;
    }
};