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
           void count(vector<vector<int>>&vec,vector<int>&curr,TreeNode* root,int targetSum)
           {
            if(!root) return;
            curr.push_back(root->val);
            targetSum-=root->val;
            if(!root->left && !root->right && targetSum==0)
            vec.push_back(curr);
            else{
            count(vec,curr,root->left,targetSum);
            count(vec,curr,root->right,targetSum);
            }
            curr.pop_back();
           }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>vec;
        vector<int>curr;
        count(vec,curr,root,targetSum);
        return vec;
    }
};