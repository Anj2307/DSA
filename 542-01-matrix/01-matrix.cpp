class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>>dist(mat.size(),vector<int>(mat[0].size(),-1));
        queue<pair<int,int>>q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0)
                   { q.push({i,j});
                    dist[i][j]=0;
                   }
            }
        }
        while(!q.empty()){
            int u=q.front().first;
            int v=q.front().second;
            q.pop();
            if(v>0 && dist[u][v-1]==-1){
                dist[u][v-1]=dist[u][v]+1;
                q.push({u,v-1});
            }
            if(u>0 && dist[u-1][v]==-1){
                dist[u-1][v]=dist[u][v]+1;
                q.push({u-1,v});
            }
            if(u<mat.size()-1 && dist[u+1][v]==-1){
                dist[u+1][v]=dist[u][v]+1;
                q.push({u+1,v});
            }
            if(v<mat[0].size()-1 && dist[u][v+1]==-1){
                dist[u][v+1]=dist[u][v]+1;
                q.push({u,v+1});
            }
        }
        return dist;
    }
};