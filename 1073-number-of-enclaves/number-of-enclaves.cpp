class Solution {
    private:
        void dfs(int i,int j,vector<vector<bool>>&vis,vector<vector<int>>&grid)
        {
            if(i<0||i>=grid.size()||j<0||j>=grid[0].size()) return;
            if(vis[i][j] || grid[i][j]==0) return;
            vis[i][j]=true;
            dfs(i-1,j,vis,grid);
            dfs(i+1,j,vis,grid);
            dfs(i,j+1,vis,grid);
            dfs(i,j-1,vis,grid);
        }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1 && !vis[i][0])
            dfs(i,0,vis,grid);
            if(grid[i][m-1]&& !vis[i][m-1])
            dfs(i,m-1,vis,grid);
        }
        for(int i=0;i<m;i++)
        {
            if(grid[0][i]==1 &&!vis[0][i])
            dfs(0,i,vis,grid);
            if(grid[n-1][i]==1 && !vis[n-1][i])
            dfs(n-1,i,vis,grid);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && !vis[i][j])
                      count++;
            }
        }
        return count;
    }
};