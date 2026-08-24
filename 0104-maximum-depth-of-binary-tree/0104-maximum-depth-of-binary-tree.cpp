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
    int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        queue<TreeNode*> q;
        q.push(root);
        int n=0;
        while(!q.empty()){
            int x=q.size();
            for(int i=0;i<x;i++){
                if(q.front()->left!=nullptr) q.push(q.front()->left);
                if(q.front()->right!=nullptr) q.push(q.front()->right);
                q.pop();
            }
            n++;
        }
        return n;
    }
};