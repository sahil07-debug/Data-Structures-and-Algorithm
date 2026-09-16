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
 
    ListNode* merge(ListNode*x,ListNode*y){
        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;
        while(x!=nullptr && y!=nullptr){
           if(x->val<=y->val){
            temp->next=x;
            temp=x;
            x=x->next;
           }
           else{
            temp->next=y;
            temp=y;
            y=y->next;
           }
             
        }
        if(x) temp->next=x;
        if(y) temp->next=y;
        return dummy->next;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast =fast->next->next;
        }
        ListNode*right=slow->next;
        slow->next=nullptr;
        ListNode*x=sortList(head);
        ListNode*y=sortList(right);
        return merge(x,y);
    }
};