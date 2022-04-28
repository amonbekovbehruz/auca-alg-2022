struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = head;
        ListNode *curr = prev->next;
    
        while (curr != nullptr)
        {
            if(curr->val == val) {
                ListNode *temp = curr;
                curr = curr->next;
                prev->next = temp->next;
                
                delete temp;
            }

            if(curr != nullptr) {
                prev = curr;
                curr = curr->next;
            }
        }
        
        return head;
    }
};