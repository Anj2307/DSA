class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>>dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        int n=grid.size();
        int m=grid[0].size();
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<m;k++)
            {
                if(j==k) dp[n-1][j][k]=grid[n-1][k];
                else dp[n-1][j][k]=grid[n-1][k]+grid[n-1][j];
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j1=0;j1<m;j1++)
            {
                for(int j2=0;j2<m;j2++){
                int maxi=-1e8;
                for(int a=-1;a<2;a++)
                {
                    for(int b=-1;b<2;b++)
                    {
                        int value=0;
                        if(j1==j2) value=grid[i][j1];
                        else value=grid[i][j1]+grid[i][j2];
                        if(j1+a>=0 && j1+a<m && j2+b>=0 && j2+b<m)
                        {
                            value+=dp[i+1][j1+a][j2+b];
                        }
                        else value=-1e8;
                        maxi=max(value,maxi);
                    }

                }
                dp[i][j1][j2]=maxi;
            }
            }

        }
        return dp[0][0][m-1];
    }
};