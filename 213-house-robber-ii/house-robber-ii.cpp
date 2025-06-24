class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>dp(nums.size()-1,-1);
         dp[0]=nums[0];
         if(nums.size()==1) return nums[0];
        for(int i=1;i<nums.size()-1;i++)
        {
            int a=0;
            if(i<2) a=0;
            else a=dp[i-2];
            dp[i]=max(nums[i]+a,dp[i-1]);
        }
        int b=dp[nums.size()-2];
        dp[0]=nums[1];
        for(int i=1;i<nums.size()-1;i++)
        {
           int a=0;
           if(i<2) a=0;
           else a=dp[i-2];
           dp[i]=max(nums[i+1]+a,dp[i-1]);
        }
        return max(b,dp[nums.size()-2]);
    }
};