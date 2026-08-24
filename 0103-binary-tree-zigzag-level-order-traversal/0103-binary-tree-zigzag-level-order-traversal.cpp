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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return{};
        stack<TreeNode*>q;
        stack<TreeNode*>st;
        q.push(root);
        vector<vector<int>>ans;
        while(!q.empty() || !st.empty()){
            vector<int>a;
            if(!q.empty()){
                while(!q.empty()){
                    if(q.top()->left!=nullptr) st.push(q.top()->left);
                    if(q.top()->right!=nullptr) st.push(q.top()->right);
                    a.push_back(q.top()->val);
                    q.pop();
                }
            }
            else{
                while(!st.empty()){
                    if(st.top()->right!=nullptr) q.push(st.top()->right);
                    if(st.top()->left!=nullptr) q.push(st.top()->left);
                    a.push_back(st.top()->val);
                    st.pop();
                }
            }
            ans.push_back(a);
        }
        return ans;
    }
};