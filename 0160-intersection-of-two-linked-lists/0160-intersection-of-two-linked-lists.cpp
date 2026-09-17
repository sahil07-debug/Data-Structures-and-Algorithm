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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode* l1=headA;
        ListNode* l2=headB;
        int count=0;
        while(l1->next!=nullptr){
            count++;
            l1=l1->next;
        }
        while(l2->next!=nullptr){
            count--;
            l2=l2->next;
        }
        l1=headA;
        l2=headB;
        if(count<0){
           for(int i=0;i>count;i--){
            l2=l2->next;
           }
        }
        if(count>0){
            for(int i=0;i<count;i++){
                l1=l1->next;
            }
        }
        while(l1!=nullptr){
            if(l1==l2) return l1;
            l1=l1->next;
            l2=l2->next;
        }
        return nullptr;
    }
};