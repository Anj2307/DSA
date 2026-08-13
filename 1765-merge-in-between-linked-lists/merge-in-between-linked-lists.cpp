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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    
            ListNode* tmp=list1;
            ListNode* ai=nullptr;
            ListNode* bi=nullptr;
            int r=0;

            while(tmp){
                r++;
                if(r==a)
                    ai=tmp;
                if(r==b)
                    {
                        bi=tmp;
                        break;
                    }

                tmp=tmp->next;
                
            }
            if(bi && bi->next)
            bi=bi->next->next;
            else bi=nullptr;
            ai->next=list2;
            while(list2->next){
                list2=list2->next;
            }
            list2->next=bi;
        
        return list1;
    }
};