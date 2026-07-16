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
    TreeNode* tar = nullptr;
    
    unordered_map<TreeNode*, TreeNode*> parentf(TreeNode* root, int start){
        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            auto p = q.front(); q.pop();

            if(p->val == start) tar = p;
            if(p->left){
                parent[p->left] = p;
                q.push(p->left);
            }
            if(p->right){
                parent[p->right] = p;
                q.push(p->right);
            }
        }
        return parent;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent = parentf(root, start);
        unordered_set<int> s;
        
        int take = 0;
        queue<TreeNode*> q;
        
        q.push(tar);
        s.insert(tar->val);

        while(!q.empty()){
            int sz = q.size();
            bool progressed = false;

            for(int i = 0; i < sz; i++) {
                auto p = q.front(); q.pop();

                
                if(p->left && !s.contains(p->left->val)){
                    q.push(p->left);
                    s.insert(p->left->val);
                    progressed = true;
                }
                
                if(p->right && !s.contains(p->right->val)){
                     q.push(p->right);
                     s.insert(p->right->val);
                     progressed = true;
                }
                
                if(parent.count(p) && !s.contains(parent[p]->val)) {
                    q.push(parent[p]);
                    s.insert(parent[p]->val);
                    progressed = true;
                }
            }
            
            if(progressed) {
                take++;
            }
        }
        return take;
    }
};
