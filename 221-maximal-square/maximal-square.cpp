class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<pair<int, int>>> p(m, vector<pair<int, int>>(n, {0, 0}));
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int mx = 0;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    p[i][j].first = (j == n - 1) ? 1 : p[i][j + 1].first + 1;
                    p[i][j].second = (i == m - 1) ? 1 : p[i + 1][j].second + 1;
                    
                    if (i == m - 1 || j == n - 1) {
                        dp[i][j] = 1; 
                    } else {
                        dp[i][j] = min({p[i][j].first, p[i][j].second, dp[i + 1][j + 1] + 1});
                    }
                    mx = max(mx, dp[i][j]);
                } else {
                    p[i][j] = {0, 0};
                    dp[i][j] = 0;
                }
            }
        }
        
        return mx * mx; 
    }
};
