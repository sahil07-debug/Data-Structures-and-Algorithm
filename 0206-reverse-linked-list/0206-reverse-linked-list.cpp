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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr) return head;
        if(head->next==nullptr) return head;
        if(head->next->next==nullptr){
            ListNode* temp=head->next;
            temp->next=head;
            head->next=nullptr;
            return temp;
        }
        ListNode* first=head;
        ListNode* second=head->next;
        ListNode* third=head->next->next;
        first->next=nullptr;
        while(third!=nullptr){
            second->next=first;
            first=second;
            second=third;
            third=third->next;
        }
        second->next=first;
        return second;
    }
};