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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next||k<=1)
            return head;
        
        ListNode dummy(0);
        dummy.next=head;
        ListNode* prevend= &dummy;

        while(1){
            ListNode* kth=prevend;
            for(int i=0;i<k && kth;++i){
                kth=kth->next;
            }
            if(!kth) break;

            ListNode* gs=prevend->next;
            ListNode* ns=kth->next;

            ListNode* prev=ns;
            ListNode* curr=gs;
            while(curr!=ns){
                ListNode* tmp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=tmp;
            }
            prevend->next=kth;
            prevend=gs;


        }
        return dummy.next;
    }
};