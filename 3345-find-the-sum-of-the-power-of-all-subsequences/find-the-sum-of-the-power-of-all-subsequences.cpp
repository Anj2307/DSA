class Solution {
    const int mod=1e9+7;
    int help(int idx, int sum,int k, vector<int>&nums,vector<int>&power,vector<vector<vector<int>>>&dp,int count)
    {
        if(sum==k)
        return power[nums.size()-count];
        if(idx==nums.size() || sum>k)
        return 0;
        if(dp[idx][count][sum]!=-1) return dp[idx][count][sum];
        return dp[idx][count][sum]=(help(idx+1,sum+nums[idx],k,nums,power,dp,count+1)+help(idx+1,sum,k,nums,power,dp,count))%mod;
    }
public:
    int sumOfPower(vector<int>& nums, int k) {
        vector<int>power(nums.size(),1);
        power[0]=1;
        for(int i=1;i<nums.size();i++)
        {
              power[i]=(power[i-1]*2)%mod;
        }
        vector<vector<vector<int>>>dp(nums.size(),vector<vector<int>>(nums.size(),vector<int>(k+1,-1)));
        return help(0,0,k,nums,power,dp,0);
    }
};