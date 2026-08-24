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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==nullptr) return{};
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        vector<int>ans;
        while(!st.empty()){
            if(st.top().second==1){
                st.top().second++;
                if(st.top().first->left!=nullptr) st.push({st.top().first->left,1});       
            }
            else if(st.top().second==2){
                st.top().second++;
                if(st.top().first->right!=nullptr) st.push({st.top().first->right,1});     
            }
            else{
                ans.push_back(st.top().first->val);
                st.pop();
            }
        }
        return ans;
    }
};