

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        
        string result = "";
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            if (curr == nullptr) {
                result += "#,";
            } else {
                result += to_string(curr->val) + ",";
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        
        
        if (!result.empty()) result.pop_back();
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;
        
        stringstream ss(data);
        string str;
        
        
        getline(ss, str, ',');
        if (str == "#") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            
            
            if (getline(ss, str, ',')) {
                if (str != "#") {
                    curr->left = new TreeNode(stoi(str));
                    q.push(curr->left);
                } else {
                    curr->left = nullptr;
                }
            }
            
            // Process Right Child
            if (getline(ss, str, ',')) {
                if (str != "#") {
                    curr->right = new TreeNode(stoi(str));
                    q.push(curr->right);
                } else {
                    curr->right = nullptr;
                }
            }
        }
        
        return root;
    }
};
