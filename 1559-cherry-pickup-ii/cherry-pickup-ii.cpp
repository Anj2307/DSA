class Solution {
private: 
    int f(int i, int j1, int j2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int r_size = grid.size();
        int c_size = grid[0].size();
        
        // Out of bounds check
        if (j1 < 0 || j2 < 0 || j1 >= c_size || j2 >= c_size)
            return -1e8;
        
        // Base case: last row
        if (i == r_size - 1) {
            if (j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }
        
        // Memoization check
        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];
        
        // Determine cherries collected at current step
        int current_cherries = (j1 == j2) ? grid[i][j1] : (grid[i][j1] + grid[i][j2]);
        
        int ma = -1e8;
        // Explore all 9 next state combinations
        for (int r = -1; r <= 1; r++) {
            for (int c = -1; c <= 1; c++) {
                ma = max(ma, current_cherries + f(i + 1, j1 + r, j2 + c, grid, dp));
            }
        }
        
        return dp[i][j1][j2] = ma;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r_size = grid.size();
        int c_size = grid[0].size();
        vector<vector<vector<int>>> dp(r_size, vector<vector<int>>(c_size, vector<int>(c_size, -1)));
        return f(0, 0, c_size - 1, grid, dp);   
    }
};
