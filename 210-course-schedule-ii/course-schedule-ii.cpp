class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>vec(numCourses);
        vector<int>indegree(numCourses,0);
        vector<int>visited(numCourses,0);
        for(auto i: pre)
        {
            vec[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int>q;
        int num=0;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0)
            {
                q.push(i);
                num++;
            }
            
        }
        vector<int>v;
       
        while(!q.empty()){
            int u= q.front(); q.pop();
            v.push_back(u);
            if(!visited[u]){
                visited[u]=1;
                for(auto i: vec[u])
                {
                    indegree[i]--;
                    if(indegree[i]==0){
                        num++;
                        q.push(i);

                    }
                }
            }
        }
        if(num!=numCourses) return {};
       return v;
    }
};