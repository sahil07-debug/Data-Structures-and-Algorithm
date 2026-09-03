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
    bool findTarget(TreeNode* root, int k) {
        vector<int>nums;
        stack<pair<TreeNode*,int>>st;
        st.push({root,0});
        while(!st.empty()){
           st.top().second++;
           if(st.top().second==1){
             if(st.top().first->left)st.push({st.top().first->left,0});
           }
           else if(st.top().second==2){
            nums.push_back(st.top().first->val);
              if(st.top().first->right)st.push({st.top().first->right,0});

           }
           else if(st.top().second==3){
             st.pop();
           }
          
        }
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            if(nums[i]+nums[j]==k)return true;
            else if(nums[i]+nums[j]>k)j--;
            else i++;
        }
        return false;
    }
};