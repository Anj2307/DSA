class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       vector<vector<int>>adj(graph.size());
       vector<int> ind(graph.size(),0);
       vector<int> res;
       queue<int>q;
       for(int i=0;i<graph.size();i++)
       {
        for(auto j: graph[i])
        {
            adj[j].push_back(i);
        }
          ind[i]=graph[i].size();
          if(ind[i]==0) 
          {q.push(i);
           res.push_back(i);
       }
       }
       
       while(!q.empty())
       {
          int i=q.front();
          q.pop();
          for(int j=0;j<adj[i].size();j++)
          {
            ind[adj[i][j]]--;
            if(ind[adj[i][j]]==0) {
                q.push(adj[i][j]);
                res.push_back(adj[i][j]);
          }
          }
       }
          sort(res.begin(),res.end());
          return res;
       }
       
    

       
        
    
};