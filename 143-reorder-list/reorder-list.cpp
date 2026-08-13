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
    void reorderList(ListNode* head) {
        if(!head||!head->next) return;
        stack<ListNode*>st;
        ListNode* temp=head;
        int l=0;
        while(temp){
            st.push(temp);
            temp=temp->next;
            l++;
        }
        int r=l/2;
        temp=head;
        while(r-- && temp){
            ListNode* t=st.top();
            ListNode* t2=temp->next;
            temp->next=t;
            t->next=t2;
            temp=t2;
            st.pop();
        }
        temp->next=nullptr;
    }
};