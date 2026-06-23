class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
       
        if (n == 0) return true; 
        
        
        vector<int> color(n, -1); 
        
       
        for (int i = 0; i < n; i++) {
           
            if (color[i] != -1) continue; 
            
            queue<int> q;
            q.push(i);
            color[i] = 0;
            
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                for (int neighbor : graph[u]) {
                
                    if (color[neighbor] == color[u]) {
                        return false; 
                    }
                   
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[u];
                        q.push(neighbor);
                    }
                }
            }
        }
        return true;
    }
};
