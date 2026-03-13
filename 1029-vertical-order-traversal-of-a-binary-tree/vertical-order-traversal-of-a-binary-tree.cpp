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
        
        if(!root) return {};

        map<int, map<int, multiset<int>>> vec;

        queue<pair<TreeNode*, pair<int,int>>> q;

        q.push({root,{0,0}});

        while(!q.empty()){

            auto u = q.front();
            q.pop();

            TreeNode* node = u.first;
            int row = u.second.first;
            int col = u.second.second;

            vec[col][row].insert(node->val);

            if(node->left)
                q.push({node->left,{row+1,col-1}});

            if(node->right)
                q.push({node->right,{row+1,col+1}});
        }

        vector<vector<int>> v;

        for(auto &i : vec){

            vector<int> col;

            for(auto &j : i.second){

                col.insert(col.end(), j.second.begin(), j.second.end());

            }

            v.push_back(col);
        }

        return v;
    }
};