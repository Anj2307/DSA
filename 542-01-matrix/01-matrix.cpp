class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    ans[i][j]=0;
                    pq.push({i,j});
                }
            }
        }
        vector<int> dirx = {1,0,-1,0};
        vector<int> diry = {0,1,0,-1};
        while(!pq.empty()){
            int i = pq.front().first;
            int j = pq.front().second;
            pq.pop();
            for(int d=0;d<4;d++){
                int x = i+dirx[d];
                int y = j+diry[d];
                if(x>=0 &&x<n && y>=0 && y<m && ans[x][y]==-1){
                    ans[x][y] = 1+ans[i][j];
                    pq.push({x,y});
                }
            }
        }
        return ans;
    }
};