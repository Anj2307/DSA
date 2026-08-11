class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),1e9);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<=i+nums[i]&&j<nums.size();j++){
                dp[j]=min(dp[j],1+dp[i]);
            }
        }
        return dp[nums.size()-1];
    }
};