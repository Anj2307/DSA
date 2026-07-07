class Solution {
    private:
    int f(vector<vector<int>>& o,vector<vector<int>>& dp, int m, int n, int r, int c){
        if(r>=m || c>=n || o[r][c])
        {
            return 0;
        }
        if(r==m-1 && c==n-1) return 1;
        if(dp[r][c]!=-1){
            return dp[r][c];
        }
        dp[r][c]=f(o,dp,m,n,r+1,c)+f(o,dp,m,n,r,c+1);

        return dp[r][c];
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        vector<vector<int>>dp(o.size(),vector<int>(o[0].size(),-1));
        return f(o,dp,o.size(),o[0].size(),0,0);
    }
};