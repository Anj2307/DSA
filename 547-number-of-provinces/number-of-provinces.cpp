class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited,int u){
        visited[u]=1;
        for(int i=0;i<isConnected[u].size();i++){
            if(isConnected[u][i]==1 && !visited[i])
            {
                dfs(isConnected,visited,i);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>visited(isConnected.size(),0);
        int c=0;
        for(int i=0;i<visited.size();i++){
            if(visited[i]==0)
            {
                c++;
                dfs(isConnected,visited,i);
            }

        }
        return c;
    }
};