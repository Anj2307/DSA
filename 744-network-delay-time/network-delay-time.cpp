class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e9);
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        dist[k]=0;
        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            auto[d,v]=pq.top();pq.pop();
            for(auto [u,ds]:adj[v])
            {
                if(d+ds<dist[u])
                {
                    dist[u]=d+ds;
                    pq.push({dist[u],u});
                }
            }
        }
        int m=INT_MIN;
        for(auto i: dist)
        {
            if(i==1e9) return -1;
            m=max(i,m);
        }
        
       return m;
    }
};