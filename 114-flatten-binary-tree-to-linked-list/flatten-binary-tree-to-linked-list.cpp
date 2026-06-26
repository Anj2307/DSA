class Solution {
private:

    TreeNode* prevnode = nullptr; 

public:
    void flatten(TreeNode* root) {
        if (!root) return;
        
        
        flatten(root->right);
        flatten(root->left);
        
        
        root->right = prevnode;
        root->left = nullptr;
        
        
        prevnode = root;
    }
};
