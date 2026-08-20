class Solution {
private:
    int f(vector<vector<int>>& dp, vector<int>& prices, int fee, int i, int buy){
        if(i>=prices.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy]=max(-prices[i]+f(dp,prices,fee,i+1,0),f(dp,prices,fee,i+1,1));
        }else {
           return  dp[i][buy]=max(prices[i]-fee+f(dp,prices,fee,i+1,1),f(dp,prices,fee,i+1,0));
        }

    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return f(dp,prices,fee,0,1);
    }
};