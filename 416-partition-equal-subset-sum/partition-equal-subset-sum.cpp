class Solution {
private:
    int dp[201][10001]; 
    
    bool f(int target, vector<int>& nums, int n) {
        if (target == 0) return true;
        if (n >= nums.size()) return false;
        
        
        if (dp[n][target] != -1) return dp[n][target];
        
        bool pick = false;
        if (target >= nums[n]) {
            pick = f(target - nums[n], nums, n + 1);
        }
        bool notPick = f(target, nums, n + 1);
        
        return dp[n][target] = pick || notPick;
    }
    
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int i : nums) {
            totalSum += i;
        }
        
        if (totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        
        
        memset(dp, -1, sizeof(dp));
        
        return f(target, nums, 0);
    }
};
