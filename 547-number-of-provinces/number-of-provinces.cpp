class Solution {
private:
         void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i)
         {
            visited[i]=true;
            for(int j=0;j<isConnected[i].size();j++)
            {
                if( isConnected[i][j]!=0 && !visited[j])
                {
                    dfs(isConnected,visited,j);
                }
            }
         }        
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(),false);
        int count=0;
        for(int i=0;i<isConnected.size();i++)
        {
            if(!visited[i])
            {
                dfs(isConnected,visited,i);
                count++;
            }
        }
        return count;
    }
};