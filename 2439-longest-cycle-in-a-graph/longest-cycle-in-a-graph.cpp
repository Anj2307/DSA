class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited(n, false);
        vector<int> depth(n, -1);
        int maxCycle = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int node = i;
            unordered_map<int, int> localDepth;
            int d = 0;

            
            while (node != -1 && !visited[node]) {
                visited[node] = true;
                localDepth[node] = d++;
                node = edges[node];
            }

        
            if (node != -1 && localDepth.count(node)) {
                maxCycle = max(maxCycle, d - localDepth[node]);
            }
        }

        return maxCycle;
    }
};
