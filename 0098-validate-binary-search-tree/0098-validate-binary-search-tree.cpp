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
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)return true;
        queue<tuple<TreeNode*,long long,long long>>q;
        q.push({root,LLONG_MAX,LLONG_MIN});
        while(!q.empty()){
            auto[node,max,min]=q.front();
            q.pop();
            if(node->val>=max || node->val<=min) return false;
            if(node->left!=nullptr){
                q.push({node->left,node->val,min});
            }
            if(node->right!=nullptr){
                q.push({node->right,max,node->val});
            }
        }
        return true;
    }
};