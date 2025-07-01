class Solution {
    int dfs(vector<vector<pair<int,int>>>& graph, int idx, vector<bool>& vis) {
        vis[idx] = true;
        int count = 0;
        for (int i = 0; i < graph[idx].size(); i++) {
            if (!vis[graph[idx][i].first]) {
                if (graph[idx][i].second == 1) {
                    count += 1 + dfs(graph,graph[idx][i].first, vis);  // Reorder needed
                } else {
                    count += dfs(graph, graph[idx][i].first, vis);      // No reorder
                }
            }
        }
        return count;
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>graph(n);
        for (const auto& edge : connections) {
            graph[edge[0]].push_back({edge[1],1});// original direction
            graph[edge[1]].push_back ({edge[0],0});  // reverse direction (no reorder needed)
        }

        vector<bool> vis(n, false);
        return dfs(graph, 0, vis);
    }
};
