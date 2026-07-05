class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            if(dp[i])
            {
                for(int j=1;j<nums[i]+1;j++)
                {
                    if(i+j<dp.size())
                    dp[i+j]=1;
                }
            }
            if(dp[nums.size()-1]==1) return true;
        }

        return false;

    }
};