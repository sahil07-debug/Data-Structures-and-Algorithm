/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*a=root;
        while(a!=nullptr){
            if((a->val>p->val && a->val<q->val) || (a->val<p->val&&a->val>q->val)) return a;
            if((a->val==p->val || a->val==q->val)) return a;
            if(a->val>p->val)a=a->left;
            else if(a->val<p->val)a=a->right;
        }
        return a;
    }
};