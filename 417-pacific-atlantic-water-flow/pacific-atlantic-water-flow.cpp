class Solution {
public:
    int n, m;
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        visited[r][c] = true;
        
        for (auto dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];

           
            if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                !visited[nr][nc] &&
                heights[nr][nc] >= heights[r][c]) {
                dfs(nr, nc, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        
        for (int i = 0; i < n; ++i) dfs(i, 0, heights, pacific);       
        for (int j = 0; j < m; ++j) dfs(0, j, heights, pacific);         

        
        for (int i = 0; i < n; ++i) dfs(i, m - 1, heights, atlantic);    
        for (int j = 0; j < m; ++j) dfs(n - 1, j, heights, atlantic);    

        
        vector<vector<int>> result;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
