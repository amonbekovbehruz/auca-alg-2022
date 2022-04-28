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
    ListNode* swapNodes(ListNode* head, int k) {
        vector<ListNode*> list;
        for(ListNode* curr = head; curr != nullptr; curr = curr->next) {
            list.push_back(curr);
        }

        ListNode *temp;
        ListNode *prev = head;
        ListNode *curr = prev->next;
        
        for(ListNode *t = head; t != nullptr; t = t->next) {
            list.push_back(t);    
        }

        for(int i = 0; i < k; i++) {
            prev = curr;
            curr = curr->next;
        }

        ListNode* swapNode = list[list.size()- (k - 1)];
        ListNode* prevSwapNode = list[list.size()- (k - 2)];

        prev->next = swapNode;
        prevSwapNode->next = curr;
        temp = swapNode;
        swapNode->next = curr->next;
        curr->next = temp->next;

        return head;
    }
};