class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int m = grid.size(), n = grid[0].size();
        visited[r][c] = true;
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1 && !visited[nr][nc]) {
                dfs(nr, nc, grid, visited);
            }
        }
    }

    int countIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                    dfs(i, j, grid, visited);
                }
            }
        }
        return count;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        
        if (countIslands(grid) != 1) return 0;
        
        int m = grid.size(), n = grid[0].size();
        
    
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        
        return 2;
    }
};
