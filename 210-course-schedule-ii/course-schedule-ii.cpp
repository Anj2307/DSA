class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty())
        {
            int n=q.front();q.pop();
            topo.push_back(n);
            for(auto it: adj[n])
            {
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        if(topo.size()<numCourses) return{};
        return topo;
        
        
    }
};