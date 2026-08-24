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
        int x=0;
        
private:
    void f(TreeNode* root, int mi)
    {
        if(!root) return;
        if(root->val>=mi) x++;
        mi=max(mi,root->val);
        f(root->left,mi);
        f(root->right,mi);
       
    }
public:
    int goodNodes(TreeNode* root) {
        int m=INT_MIN;
        f(root,m);
        return x;
    }
};