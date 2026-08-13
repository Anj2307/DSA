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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* let=nullptr;
        ListNode* rigt=nullptr;
        ListNode* b_l=nullptr;
        ListNode* temp=head;
        int r=0;
        while(r!=right && temp){
            r++;
            if(r==left-1){
                b_l=temp;
            }
            if(r==left){
                let= temp;
            }
            if(r==right){
                rigt=temp;
            }
            temp=temp->next;
        }

        ListNode* prev=rigt->next;

        ListNode* curr=let;
        while(curr!=temp){
            ListNode* t=curr->next;
            curr->next=prev;
            prev=curr;
            curr=t;
        }
        if(b_l){
            b_l->next=rigt;
        }else {
            return rigt;
        }
        return head;
    }
};