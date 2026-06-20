class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>>q;
        int e=0;
        for(int i=0;i<grid.size();i++)
        {
            for (int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    
                }
                else if(grid[i][j]==1)
                e++;
            }
        }
        int c=0;

        while(!q.empty()){
            auto p=q.front();
            auto g=p.first;
            q.pop();
            c=p.second;
            
            if(g.first>0&&grid[g.first-1][g.second]==1)
            {
                grid[g.first-1][g.second]=2;
                q.push({{g.first-1,g.second},p.second+1});
                e--;
            }
            if(g.first<grid.size()-1&&grid[g.first+1][g.second]==1)
            {
                grid[g.first+1][g.second]=2;
                q.push({{g.first+1,g.second},p.second+1});
                e--;
            }

            if(g.second>0&&grid[g.first][g.second-1]==1)
            {
                grid[g.first][g.second-1]=2;
                q.push({{g.first,g.second-1},p.second+1});
                e--;
            }

            if(g.second<grid[0].size()-1&&grid[g.first][g.second+1]==1)
            {
                grid[g.first][g.second+1]=2;
                q.push({{g.first,g.second+1},p.second+1});
                e--;
            }
        }
        
       
        if(!e) return c;
        return -1;
        

    }
};