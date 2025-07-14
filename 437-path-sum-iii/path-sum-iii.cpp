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
    private:
    int countpaths(TreeNode* node, long long sum)
    {
        if(!node) return 0;
        int count=0;
        if(node->val==sum) count++;
        count+=countpaths(node->left,sum-node->val);
        count+=countpaths(node->right,sum-node->val);
        return count;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        int pathsRoot = countpaths(root, targetSum);
        int pathsLeft = pathSum(root->left, targetSum);
        int pathsRight = pathSum(root->right, targetSum);
        return pathsRoot + pathsLeft + pathsRight;
    }
};