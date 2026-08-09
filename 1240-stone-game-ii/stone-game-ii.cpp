class Solution {
private:
    int f(int i,int m, int n, vector<vector<int>>& dp, vector<int>& suff){
        if(i>=n)
            return 0;
        if(2*m>=n-i)
            return suff[i];
        if(dp[i][m]!=-1) return dp[i][m];
        int ans=0;
        for (int x = 1; x <= 2 * m && i + x <= n; x++){
            int newm=max(m,x);
            int curr=suff[i]-f(x+i,newm,n,dp,suff);
            ans=max(curr,ans);
        }
        return dp[i][m]=ans;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        vector<int>suff(n+1,0);
        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1]+piles[i];
        }
        return f(0,1,n,dp,suff);
    }
};