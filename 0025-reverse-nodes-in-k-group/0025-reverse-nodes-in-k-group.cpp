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
    ListNode* findnode(ListNode* head,int k){
        for(int i=1;i<k;i++){
            head=head->next;
            if(head==nullptr) return nullptr;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prevnode=nullptr;
        while(temp!=nullptr){
            ListNode*knode=findnode(temp,k);
            if(knode==nullptr){
                if(prevnode) prevnode->next=temp;
                break;
            }
            ListNode* nextnode=knode->next;
            knode->next=nullptr;
            reverseList(temp);

            if(temp==head) head=knode;
            else prevnode->next=knode;

            prevnode=temp;
            temp=nextnode;

        }
        return head;
    }
};