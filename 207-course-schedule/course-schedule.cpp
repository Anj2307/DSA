class Solution {
private:
    bool dfs(int n,vector<vector<int>>& vec, vector<int>& vis, vector<int>& path){
        vis[n]=1;
        path[n]=1;
        for(auto it: vec[n]){
            if(!vis[it])
            {
                if(dfs(it,vec,vis,path)==true) return true;
            }
            else if(path[it])
            {
                return true;
            }
        }
        path[n]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        for(auto it : prerequisites){
            adjlist[it[1]].push_back(it[0]);
        }
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        for(int i=0;i<vis.size();i++)
        {
            if(!vis[i]) 
            {
                if(dfs(i,adjlist,vis,pathvis)==true) return false;
            }
        }
        return true;
        

    }
};