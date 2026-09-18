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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        int sum=l1->val+l2->val;
        int i=sum/10;
        sum=sum%10;
        ListNode*head=new ListNode(sum,nullptr);
        ListNode*temp=head;
        l1=l1->next;
        l2=l2->next;
        while(l1!=nullptr || l2!=nullptr || i!=0){
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;
            sum=i+x+y;
            i=sum/10;
            sum=sum%10;
            ListNode* newnode=new ListNode(sum,nullptr);
            temp->next=newnode;
            temp=newnode;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        return head;
    }
};