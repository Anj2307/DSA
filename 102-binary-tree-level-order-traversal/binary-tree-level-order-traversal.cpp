class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        if(root == nullptr) return {};

        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> vec;

        q.push({root,0});

        while(!q.empty())
        {
            auto p = q.front();
            q.pop();

            if(vec.size() == p.second)
                vec.push_back({});

            vec[p.second].push_back(p.first->val);

            if(p.first->left != nullptr)
                q.push({p.first->left, p.second + 1});

            if(p.first->right != nullptr)
                q.push({p.first->right, p.second + 1});
        }

        return vec;
    }
};