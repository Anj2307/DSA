class Solution {
public:
    int help(int i1, int i2, int j1, int j2,
             vector<vector<vector<vector<int>>>>& dp,
             vector<vector<int>>& grid, int m, int n) {

        // Base cases
        if (i1 >= m || i2 >= m || j1 >= n || j2 >= n ||
            grid[i1][j1] == -1 || grid[i2][j2] == -1)
            return -1e8;

        // Both reach the end
        if (i1 == m - 1 && j1 == n - 1 && i2 == m - 1 && j2 == n - 1)
            return grid[m - 1][n - 1];

        // Memoized
        if (dp[i1][i2][j1][j2] != -1)
            return dp[i1][i2][j1][j2];

        // Current cherries
        int ch = (i1 == i2 && j1 == j2) ? grid[i1][j1]
                                       : grid[i1][j1] + grid[i2][j2];

        // Try all 4 combinations of moves
        int next = max({
            help(i1 + 1, i2 + 1, j1, j2, dp, grid, m, n),
            help(i1 + 1, i2, j1, j2 + 1, dp, grid, m, n),
            help(i1, i2 + 1, j1 + 1, j2, dp, grid, m, n),
            help(i1, i2, j1 + 1, j2 + 1, dp, grid, m, n)
        });

        ch += next;
        return dp[i1][i2][j1][j2] = ch;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Initialize 4D DP with -1
        vector<vector<vector<vector<int>>>> dp(
            m, vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(n, -1)))
        );

        return max(0, help(0, 0, 0, 0, dp, grid, m, n));
    }
};
