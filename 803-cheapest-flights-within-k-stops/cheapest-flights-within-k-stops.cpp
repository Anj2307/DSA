class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : flights)
            adj[e[0]].push_back({e[1], e[2]});

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<int>> dist(k + 2, vector<int>(n, INT_MAX));

        dist[0][src] = 0;
        pq.push({0, src, 0});      

        while(!pq.empty()){

            auto cur = pq.top();
            pq.pop();

            int cost = cur[0];
            int u = cur[1];
            int edges = cur[2];

            if(u == dst)
                return cost;

            if(edges == k + 1)
                continue;

            for(auto &[v, wt] : adj[u]){

                if(cost + wt < dist[edges + 1][v]){
                    dist[edges + 1][v] = cost + wt;
                    pq.push({cost + wt, v, edges + 1});
                }
            }
        }

        return -1;
    }
};