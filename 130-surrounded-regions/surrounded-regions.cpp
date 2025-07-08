class Solution {
    private: 
        void dfs(int i, int j,vector<vector<bool>>&vis,vector<vector<char>>& board)
        {
            if(i<0||i>=board.size()||j<0||j>=board[0].size()) return;
            if(board[i][j]=='X' || vis[i][j]) return;
            vis[i][j]=true;
            dfs(i-1,j,vis,board);
            dfs(i,j-1,vis,board);
            dfs(i+1,j,vis,board);
            dfs(i,j+1,vis,board);
        }
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<bool>>vis(board.size(),vector<bool>(board[0].size(),false));
        for(int j=0;j<board[0].size();j++)
        {
            if(!vis[0][j] && board[0][j]=='O')
            {
                dfs(0,j,vis,board);
            }
            if(!vis[board.size()-1][j] && board[board.size()-1][j]=='O')
            dfs(board.size()-1,j,vis,board);
        }
        for(int i=0;i<board.size();i++)
        {
            if(!vis[i][0]&& board[i][0]=='O')
            dfs(i,0,vis,board);
            if(!vis[i][board[0].size()-1] && board[i][board[0].size()-1]=='O')
            dfs(i,board[0].size()-1,vis,board);
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]=='O' && !vis[i][j])
                board[i][j]='X';
            }
        }

    }
};