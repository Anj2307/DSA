class Solution {
private:
    bool dfs(int i, int j, string& word, vector<vector<char>>& board, int index, vector<vector<bool>>& vis) {
        if (index == word.length()) return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;
        if (vis[i][j] || board[i][j] != word[index]) return false;

        vis[i][j] = true;

        
        bool found = dfs(i + 1, j, word, board, index + 1, vis) ||
                     dfs(i - 1, j, word, board, index + 1, vis) ||
                     dfs(i, j + 1, word, board, index + 1, vis) ||
                     dfs(i, j - 1, word, board, index + 1, vis);

        vis[i][j] = false; // backtrack
        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(i, j, word, board, 0, vis))
                    return true;
            }
        }
        return false;
    }
};
