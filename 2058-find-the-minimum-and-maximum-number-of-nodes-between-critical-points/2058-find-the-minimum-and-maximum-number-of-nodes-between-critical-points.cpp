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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* a=head;
        if(a==nullptr) return {-1,-1};
        ListNode* b=a->next;
        if(b==nullptr) return {-1,-1};
        ListNode*c=b->next;
        if(c==nullptr) return {-1,-1};
        vector<int>ans{INT_MAX,INT_MIN};
        int x=0;
        int y=0;
        int z=0;
        while(c!=nullptr){
            if(b->val<a->val && b->val<c->val){
                if(x==0){
                    x=1;
                    y=1;
                    z=1;
                }
                else{
                    int l=z-y;
                    if(l<ans[0]) ans[0]=l;
                    ans[1]=z-x;
                    y=z;
                }
            }
            else if(b->val>a->val && b->val>c->val){
                if(x==0){
                    x=1;
                    y=1;
                    z=1;
                }
                else{
                    int l=z-y;
                    if(l<ans[0]) ans[0]=l;
                    ans[1]=z-x;
                    y=z;
                }
            }
            a=b;
            b=c;
            c=c->next;
            z++;
        } 
        if(ans[0]==INT_MAX || ans[1]==INT_MIN) return {-1,-1};

        return ans;  
    }
};