class Solution {
public:
    int rob(vector<int>& nums) {

        // leave first
        vector<int>dp(nums.size()-1,0);

        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);

        dp[0]=nums[1];
        dp[1]=max(nums[1],nums[2]);

        for(int i=2;i<nums.size()-1;i++){
            dp[i]=max(dp[i-2]+nums[i+1],dp[i-1]);
        }
        int a=dp[nums.size()-2];

        // leave last wala

        vector<int>dp1(nums.size()-1,0);

        dp1[0]=nums[0];
        dp1[1]=max(nums[0],nums[1]);

        for(int i=2;i<nums.size()-1;i++){
            dp1[i]=max(dp1[i-2]+nums[i],dp1[i-1]);
        }

        int b=dp1[nums.size()-2];

        return max(a,b);
        



    }
};