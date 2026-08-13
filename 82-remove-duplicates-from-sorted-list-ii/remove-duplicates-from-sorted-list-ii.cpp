class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        
        bool head_has_dup = false;
        while (head && head->next && head->val == head->next->val) {
            int v = head->val;
            while (head && head->val == v) {
                head = head->next;
            }
            head_has_dup = true;
        }
        
        if (!head) return head;
        
        ListNode* t = head;
        while (t) {
            ListNode* t2 = t->next;
            if (!t2) break;
            
          
            if (t2->next && t2->val == t2->next->val) {
                int v = t2->val;
                while (t2 && t2->val == v) {
                    t2 = t2->next;
                }
                t->next = t2; 
            } else {
                t = t->next;
            }
        }
        return head;
    }
};
