class Solution {
public:
    int jump(vector<int>& nums) {
        
        vector<int>dp(nums.size(),-1);
        dp[0]=0;

        for(int i=0;i<nums.size();i++)
        {
            for(int j=1;j<nums[i]+1;j++)
            {
                if(i+j<nums.size())
                {
                    if(dp[i+j]==-1){
                        dp[i+j]=dp[i]+1;
                    }else
                        dp[i+j]=min(dp[i+j],dp[i]+1);
                }
            }
        }
        return dp[nums.size()-1];
    }
};