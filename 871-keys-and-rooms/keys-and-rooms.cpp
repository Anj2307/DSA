class Solution {
private:
    void dfs(int u, vector<vector<int>> &rooms, vector<int>& visited){
        visited[u]=1;
        for(auto it: rooms[u]){
            if(!visited[it])
                dfs(it,rooms,visited);
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int>visited(rooms.size(),0);
        dfs(0,rooms,visited);
        for(auto i: visited){
            if(!i) return false;
        }
        return true;
    }
};