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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>>vec;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            auto u=q.front();
            q.pop();
            if(vec.size()==u.second)
            vec.push_back({});
            vec[u.second].push_back((u.first)->val);
            if((u.first)->left) q.push({(u.first)->left,u.second+1});
            if((u.first)->right)q.push({(u.first)->right,u.second+1});
        }
        for(int i=1;i<vec.size();i+=2)
        {
            reverse(vec[i].begin(),vec[i].end());
        }
        return vec;
    }
};