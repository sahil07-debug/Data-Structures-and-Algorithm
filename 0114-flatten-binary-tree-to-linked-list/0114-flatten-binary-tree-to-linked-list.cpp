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
    void flatten(TreeNode* root) {
        if(root==nullptr)return;
        stack<pair<TreeNode*,int>>st;
        st.push({root,0});
        vector<TreeNode*>nums;
        while(!st.empty()){
            if(st.top().second==0){
                st.top().second++;
                nums.push_back(st.top().first);
                if(st.top().first->left)st.push({st.top().first->left,0});
            }
            else if(st.top().second==1){
                st.top().second++;
                if(st.top().first->right)st.push({st.top().first->right,0});
            }
            else st.pop();
        }
        for(int i=0;i<nums.size();i++){
            nums[i]->left=nullptr;
            if(i==nums.size()-1) nums[i]->right=nullptr;
            else nums[i]->right=nums[i+1];
        }
    }
};