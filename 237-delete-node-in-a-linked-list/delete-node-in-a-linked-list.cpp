/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* t=node;
        ListNode* b=node;
        while(t->next){
            int p=t->val;
            t->val=t->next->val;
            t->next->val=p;
            if(!t->next->next){
                b=t;
            }
            t=t->next;
        }
        b->next=nullptr;
        
    }
};