class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==2) q.push({i,j});
            }
        }

       // if(q.empty()) return -1;
        //vector<vector<bool>>vis(grid.size(),vector<bool>(grid[0].size(),false));
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                pair<int,int>test=q.front();q.pop();
                if(test.first>0 && grid[test.first-1][test.second]==1)
                {
                    q.push({test.first-1,test.second});
                    grid[test.first-1][test.second]=2;
                }
                if(test.first<(grid.size()-1) && grid[test.first+1][test.second]==1)
                {
                    q.push({test.first+1,test.second});
                    grid[test.first+1][test.second]=2;
                }
                if(test.second>0 && grid[test.first][test.second-1]==1)
                {
                    q.push({test.first,test.second-1});
                    grid[test.first][test.second-1]=2;
                }
                if(test.second<(grid[0].size()-1) && grid[test.first][test.second+1]==1)
                {
                    q.push({test.first,test.second+1});
                    grid[test.first][test.second+1]=2;
                }

            }
            count++;
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1) return -1;
            }
        }
        if(count==0) return 0;
        return count-1;
    }
};