class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        if(grid[0][0]!=0) return -1;

        vector<vector<int>>dist(grid.size(),vector<int>(grid.size(),INT_MAX));

        pq.push({1,{0,0}});
        dist[0][0]=1;

        vector<int>a={0,1,-1};


        while(!pq.empty()){
            auto p=pq.top(); pq.pop();
            int w=p.first;
            int x=p.second.first;
            int y=p.second.second;

            for(auto i: a){
                for(auto j: a){
                    if(!(i==0 && j==0))
                    {
                        if(x+i>=0 && x+i<grid.size() && y+j>=0 && y+j<grid.size())
                        {
                            if(grid[x+i][y+j]==0 && dist[x+i][y+j]>(w+1))
                            {
                                dist[x+i][y+j]=w+1;
                                pq.push({w+1,{x+i,y+j}});
                            }
                        }
                    }
                }
            }
            
        }

        return (dist[grid.size()-1][grid.size()-1]==INT_MAX)?-1:dist[grid.size()-1][grid.size()-1];

        


    }
};