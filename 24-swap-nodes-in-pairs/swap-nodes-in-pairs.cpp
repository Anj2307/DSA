/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * temp=head->next;
        head->next=head->next->next;
        temp->next=head;
        head=temp;
        temp=temp->next;

        while(temp && temp->next && temp->next->next){
            ListNode * t=temp->next;
            temp->next=t->next;
            t->next=temp->next->next;
            temp->next->next=t;
            temp=t;
        }
        return head;
        
    }
};