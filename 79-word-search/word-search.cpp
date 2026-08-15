class Solution {
private:
    bool f(vector<vector<char>>& board, string word,int i,int j, int r){
        if(r==word.size()) return true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size()) return false;
        
        //dfs
        vector<int>dr={-1,0,1,0};
        vector<int>dc={0,-1,0,1};
        if(board[i][j]==word[r]){
            int ch=board[i][j];
            board[i][j]='1';
                for(int k=0;k<4;k++){
                    if(f(board,word,dr[k]+i,dc[k]+j,r+1)){
                        return true;
                    }
                }
                board[i][j]=ch;
            }
            
        
        return false;
    }
        
    
public:
    bool exist(vector<vector<char>>& board, string word) {
          int m = board.size();
        int n = board[0].size();
        if (word.size() > m * n) return false;

      
        unordered_map<char, int> boardFreq;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                boardFreq[board[i][j]]++;
            }
        }

        
        unordered_map<char, int> wordFreq;
        for (char c : word) {
            wordFreq[c]++;
        }

        
        for (auto& pair : wordFreq) {
            if (boardFreq[pair.first] < pair.second) {
                return false;
            }
        }

      
        if (boardFreq[word.back()] < boardFreq[word.front()]) {
            reverse(word.begin(), word.end());
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++){
                if(f(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};