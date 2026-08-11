class Solution {
    private:
        int f(vector<int>&dp,int i,vector<int>&nums){
           if(i>=dp.size()-1) return 0;
           if(dp[i]!=-1) return dp[i];
           int min_value=1e9;
           for(int j=1;j<=nums[i];j++){
            min_value=min(min_value,1+f(dp,i+j,nums));
           }
           return dp[i]=min_value;
        }
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(), -1);
        return f(dp,0,nums);
    }
};