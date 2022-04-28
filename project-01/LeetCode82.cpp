struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        int valueToDelete;
        bool isFirst = true;
        ListNode *prevValue;
        for (ListNode *prev = head; prev != nullptr; prev = prev->next)
        {
            ListNode *prevValue = prev;
            if(isFirst) { 
                valueToDelete = prev->val;
                isFirst = false;
                continue;
            }

            if(prev->val == valueToDelete) {
                
            }
        }
        
    }
};