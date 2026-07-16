class Solution {
    vector<string> result;

    void dfs(TreeNode* root, string path) {
        if (!root) return;

       
        if (!path.empty()) path += "->";
        path += to_string(root->val);

        
        if (!root->left && !root->right) {
            result.push_back(path);
            return;
        }

        
        dfs(root->left, path);
        dfs(root->right, path);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        result.clear(); 
        dfs(root, "");
        return result;
    }
};
