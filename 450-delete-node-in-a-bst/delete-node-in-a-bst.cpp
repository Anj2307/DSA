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
        if (!root) return nullptr;
        
        // Handle the case where the root itself needs to be deleted
        if (root->val == key) {
            return f(root);
        }
        
       
        TreeNode* curr = root; 
        
        while (curr) {
            if (curr->val > key) {
                if (curr->left && curr->left->val == key) {
                    curr->left = f(curr->left);
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->right && curr->right->val == key) {
                    curr->right = f(curr->right);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }
        return root; // Always returns the true root of the modified tree
    }

    // Helper function to stitch the subtrees together upon deletion
    TreeNode* f(TreeNode* root) {
        if (!root->left) return root->right;
        else if (!root->right) return root->left;
        
        TreeNode* rc = root->right;
        TreeNode* lr = f1(root->left);
        lr->right = rc;
        return root->left;
    }

    // Finds the rightmost (largest) node in the left subtree
    TreeNode* f1(TreeNode* root) {
        if (!root->right) return root;
        return f1(root->right);
    }
};
