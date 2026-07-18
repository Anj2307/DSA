class Solution {

    long long prev_val = LLONG_MIN; 

public:
    bool isValidBST(TreeNode* root) {
       
        if (!root) return true;
        
       
        if (!isValidBST(root->left)) return false;
        
        if (root->val <= prev_val) return false;
        
        
        prev_val = root->val;
        
        
        return isValidBST(root->right);
    }
};
