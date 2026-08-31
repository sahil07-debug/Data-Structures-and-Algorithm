/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*x=new TreeNode(val);
        TreeNode* y=root;
        while(y!=nullptr){
            if(y->val>val){
                if(y->left==nullptr){
                    y->left=x;
                    return root;
                }
                y=y->left;
            }
            if(y->val<val){
                if(y->right==nullptr){
                    y->right=x;
                    return root;
                }
                y=y->right;
            }
        }
        return x;
    }
};