class Solution {
    private:
        void dfs(int u, vector<int>&vis,  vector<vector<pair<int,int>>>& adj){
            vis[u]=1;

            for(auto it: adj[u]){
                if(!vis[it.first])
                    dfs(it.first,vis,adj);
            }
        }
public:
    int minScore(int n, vector<vector<int>>& roads) {
        priority_queue<int, vector<int>, greater<int>>pq;

        vector<vector<pair<int,int>>>adj(n+1);
        
        vector<int>vis(n+1,0);

        for(auto j: roads)
        {
            adj[j[0]].push_back({j[1],j[2]});

            adj[j[1]].push_back({j[0],j[2]});
        }

        dfs(1,vis,adj);

        for(auto j: roads){
            if(vis[j[1]] && vis[j[0]]){
                pq.push(j[2]);
            }
        }

        return pq.top();

    }
};