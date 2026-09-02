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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) {
            if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            TreeNode* rightSubtree = root->right;
            TreeNode* curr = rightSubtree;
            while (curr->left != nullptr) {
                curr = curr->left;
            }
            curr->left = root->left;
            delete root;
            return rightSubtree;
        }
        TreeNode* x = root;
        while (x != nullptr) {
            if (x->val > key) {
                if (x->left != nullptr && x->left->val == key) {
                    TreeNode* y = x->left;
                    if (y->right == nullptr) {
                        x->left = y->left;
                    } else {
                        x->left = y->right;
                        TreeNode* temp = y->right;
                        while (temp->left != nullptr) {
                            temp = temp->left;
                        }
                        temp->left = y->left;
                    }
                    delete y;
                    break;
                }
                x = x->left;
            } else {
                if (x->right != nullptr && x->right->val == key) {
                    TreeNode* y = x->right;
                    if (y->right == nullptr) {
                        x->right = y->left;
                    } else {
                        x->right = y->right;
                        TreeNode* temp = y->right;
                        while (temp->left != nullptr) {
                            temp = temp->left;
                        }
                        temp->left = y->left;
                    }
                    delete y;
                    break;
                }
                x = x->right;
            }
        }
        return root;
    }
};