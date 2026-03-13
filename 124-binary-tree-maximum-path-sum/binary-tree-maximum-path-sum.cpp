class Solution {
public:

    int ans(TreeNode* root, int* maxi)
    {
        if(root == nullptr) return 0;

        int leftsum = max(0, ans(root->left, maxi));
        int rightsum = max(0, ans(root->right, maxi));

        *maxi = max(*maxi, root->val + leftsum + rightsum);

        return root->val + max(leftsum, rightsum);
    }

    int maxPathSum(TreeNode* root) {

        int maxi = INT_MIN;

        ans(root, &maxi);

        return maxi;
    }
};