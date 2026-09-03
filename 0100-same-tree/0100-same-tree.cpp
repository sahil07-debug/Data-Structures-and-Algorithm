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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(q==nullptr && p==nullptr)return true;
        if((q==nullptr && p!=nullptr)||(q!=nullptr && p==nullptr))return false;
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty()){
           if(q1.front()->val!=q2.front()->val)return false;
           if((q1.front()->left && !q2.front()->left)||(!q1.front()->left && q2.front()->left)||(q1.front()->right && !q2.front()->right)||(!q1.front()->right && q2.front()->right)) return false;
           else{
              if(q1.front()->left) q1.push(q1.front()->left);
              if(q2.front()->left)q2.push(q2.front()->left);
              if(q2.front()->right)q2.push(q2.front()->right);
              if(q1.front()->right)q1.push(q1.front()->right);
           }
           q1.pop();
           q2.pop();
        }
        return true;
    }
};