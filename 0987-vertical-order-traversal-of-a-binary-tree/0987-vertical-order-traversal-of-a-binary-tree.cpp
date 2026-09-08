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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        if (root) {
            q.push({root, {0, 0}});
        }  
        while (!q.empty()) {
            auto [node, coords] = q.front();
            q.pop();   
            int row = coords.first;
            int col = coords.second;     
            mp[col].push_back({row, node->val});   
            if (node->left) {
                q.push({node->left, {row + 1, col - 1}});
            }
            if (node->right) {
                q.push({node->right, {row + 1, col + 1}});
            }
        }
        vector<vector<int>> result;  
        for (auto& [col, nodes] : mp) {
            sort(nodes.begin(), nodes.end()); 
            vector<int> colValues;
            for (auto& [row, val] : nodes) {
                colValues.push_back(val);
            }
            result.push_back(colValues);
        }
        
        return result;
    }
};
