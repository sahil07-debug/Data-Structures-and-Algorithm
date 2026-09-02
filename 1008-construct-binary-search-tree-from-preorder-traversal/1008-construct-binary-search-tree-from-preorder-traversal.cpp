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
    TreeNode* bstFromPreorder(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return nullptr;
        TreeNode*a=new TreeNode(nums[0]);
        if(n==1)return a;
        stack<tuple<TreeNode*,long long,long long>>st;
        st.push({a,INT_MIN,INT_MAX});
        int i=1;
        while(i<n){
            TreeNode* c=new TreeNode(nums[i]);
            auto[node,x,y]=st.top();
            if(node->left && node->right){
                st.pop();
                continue;
            }
            if(nums[i]<node->val){
                if(nums[i]>x){
                    node->left=c;
                    st.push({c,x,node->val});
                    i++;
                }
                else{
                    st.pop();
                }
            }
            else if(nums[i]>node->val){
                if(nums[i]<y){
                    node->right=c;
                    st.push({c,node->val,y});
                    i++;
                }
                else{
                    st.pop();
                }
            }
        }
        return a;
    }
};