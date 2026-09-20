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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr) return head;
        if(k==0) return head;
        ListNode*temp=head;
        int total=0;
        while(temp->next!=nullptr){
           temp=temp->next;
           total++;
        }
        int n=total-(k%(total+1));
        temp->next=head;
        temp=temp->next;
        for(int i=0;i<n;i++){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;

    }
};