class Solution {
public:
    int n;
    vector<int> nums;
    vector<vector<int>> dp;

    int solve(int i, int j) {
        if (j >= n)
            return nums[i];

        if (j == n - 1)
            return max(nums[i], nums[j]);

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;

        // Remove i and j
        ans = min(ans,
                  max(nums[i], nums[j]) +
                  solve(j + 1, j + 2));

        // Remove i and j+1
        ans = min(ans,
                  max(nums[i], nums[j + 1]) +
                  solve(j, j + 2));

        // Remove j and j+1
        ans = min(ans,
                  max(nums[j], nums[j + 1]) +
                  solve(i, j + 2));

        return dp[i][j] = ans;
    }

    int minCost(vector<int>& arr) {
        nums = arr;
        n = nums.size();

        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        dp.assign(n, vector<int>(n + 1, -1));
        return solve(0, 1);
    }
};