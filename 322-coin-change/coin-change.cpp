class Solution {
private:
    int f(int i,vector<int>& dp,vector<int>&coins){
        if(i<0) return 1e8;
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int min_coins=1e8;
        for(auto j: coins){
            min_coins=min(min_coins,1+f(i-j,dp,coins));
        }
        return dp[i]=min_coins;

    }

public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        int ans = f(amount, dp, coins);
        
        
        return (ans >= 1e8) ? -1 : ans;
    }
};