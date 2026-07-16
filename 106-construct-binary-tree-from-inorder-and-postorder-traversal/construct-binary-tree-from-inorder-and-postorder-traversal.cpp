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
    TreeNode* buildTree(vector<int>&preorder, int pres, int pree, vector<int>& inorder,int ins, int ine, map<int,int>&m){
        if(pres>pree||ins>ine) return NULL;

        TreeNode* root=new TreeNode(preorder[pree]);
        int inr=m[root->val];
        int nums=inr-ins;

        root->left=buildTree(preorder,pres,pres+nums-1,inorder,ins,inr-1,m);
        root->right=buildTree(preorder,pres+nums,pree-1,inorder,inr+1,ine,m);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& preorder) {
        map<int,int>m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }

        TreeNode* root=buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);

        return root;
    }
};