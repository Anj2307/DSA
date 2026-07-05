class Solution {
private:
    bool dfs(int node, vector<int>& arr, vector<bool>& vis) {
        if (node < 0 || node >= arr.size() || vis[node]) {
            return false;
        }
        
        
        if (arr[node] == 0) {
            return true;
        }
        
        
        vis[node] = true;
        
        
        return dfs(node + arr[node], arr, vis) || dfs(node - arr[node], arr, vis);
    }

public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> vis(arr.size(), false);
        return dfs(start, arr, vis);
    }
};
