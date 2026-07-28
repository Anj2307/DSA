class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& i : redEdges){
            adj[i[0]].push_back({i[1], 0});
        }
        for(auto& j : blueEdges){
            adj[j[0]].push_back({j[1], 1});
        }
        
        vector<int> ans(n, -1);
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        
        typedef tuple<int,int,int> t;
        queue<t> q;
        
        q.push({0, 0, -1});
        visited[0][0] = true;
        visited[0][1] = true;
        ans[0] = 0;
        
        while(!q.empty()){
            auto [node, steps, last_color] = q.front();
            q.pop();
            
            if(ans[node] == -1){
                ans[node] = steps;
            }
            
            for(auto& edge : adj[node]){
                int v = edge.first;
                int next_color = edge.second;
                
                if(next_color != last_color && !visited[v][next_color]){
                    visited[v][next_color] = true;
                    q.push({v, steps + 1, next_color});
                }
            }
        }
        
        return ans;
    }
};
