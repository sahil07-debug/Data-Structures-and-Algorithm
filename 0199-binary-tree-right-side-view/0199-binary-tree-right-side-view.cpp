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
    vector<int> rightSideView(TreeNode* root) {
        if(root==nullptr) return{};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            int n=q.size();
            for(int i=0;i<n;i++){
                if(q.front()->right!=nullptr) q.push(q.front()->right);
                if(q.front()->left!=nullptr) q.push(q.front()->left);
                q.pop();
            }
        }
        return ans;
    }
};