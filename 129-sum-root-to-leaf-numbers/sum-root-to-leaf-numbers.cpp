class Solution {
private:
    void f(TreeNode* root, vector<string> &vec, string &str) {
       
        if (!root) return;

       
        string valStr = to_string(root->val);
        int addedLength = valStr.length();

       
        str += valStr;

        
        if (!root->left && !root->right) {
            vec.push_back(str);
            
            for (int i = 0; i < addedLength; i++) {
                str.pop_back();
            }
            return;
        }

       
        f(root->left, vec, str);
        f(root->right, vec, str);

      
        for (int i = 0; i < addedLength; i++) {
            str.pop_back();
        }
    }

public:
    int sumNumbers(TreeNode* root) {
        vector<string> vec;
        string str = "";
        f(root, vec, str);

        long long ans = 0;
        for (auto i : vec) {
            long long num = stoll(i);
            ans += num;
        }
        return ans;
    }
};
