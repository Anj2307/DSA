class Solution {
private:
    int timer=1;
    void dfs(int node, vector<bool>& vis, int parent, vector<vector<int>>& adj, int tin[], int low[],vector<vector<int>>& brd){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it: adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,vis,node,adj,tin,low,brd);
                low[node]=min(low[node],low[it]);

                if(low[it]>tin[node]){
                    brd.push_back({it,node});
                }
            }else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
public:
   
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<vector<int>>adj(n);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<bool>vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>>bridges;
        dfs(0,vis,-1,adj,tin,low,bridges);
        return bridges;

    }
};