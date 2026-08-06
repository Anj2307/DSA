class Solution {
private:
int timer=0;
void dfs(int node, int p, vector<bool>& vis,vector<vector<int>>& adj,int tin[], int low[], vector<vector<int>>& brd){
    vis[node]=1;
    tin[node]=low[node]=timer;
    timer++;
    for(auto it: adj[node]){
        if(it==p) continue;
        if(!vis[it]){
            dfs(it,node,vis,adj,tin,low,brd);
            low[node]=min(low[it],low[node]);
            if(low[it]>tin[node]){
                brd.push_back({node,it});
            }

        }else{
            low[node]=min(low[node],tin[it]);
        
        }
    }

}
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        vector<bool>vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>>brd;
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0,-1,vis,adj,tin,low,brd);
        return brd;
    }
};