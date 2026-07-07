class Solution {
    int f(vector<vector<int>> & grid, int r, int c,int cnt){
        if(r>=grid.size() || c>=grid[0].size() ||  c<0 || r<0 || grid[r][c]==3 || grid[r][c]==-1)
        {
            return 0;
        }
        if(grid[r][c]==2)
        {
            return (cnt==0);
        }
       int temp = grid[r][c];
        grid[r][c] = 3;
        int ans =
    f(grid,r+1,c,cnt-1)+
    f(grid,r,c+1,cnt-1)+
    f(grid,r-1,c,cnt-1)+
    f(grid,r,c-1,cnt-1);

    grid[r][c]=temp;      
    return ans;
        
        

    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r,c,cnt=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1) 
                {
                    r=i;
                    c=j;
                }
                if(grid[i][j]!=-1) cnt++;

            }
        }
        return f(grid,r,c,cnt-1);
        
    }
};