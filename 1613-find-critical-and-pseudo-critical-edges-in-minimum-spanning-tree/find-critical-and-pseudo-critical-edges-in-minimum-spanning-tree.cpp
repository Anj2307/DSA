class DSU{
    public:
        vector<int>parent;
        vector<int>rank;
        vector<int>size;
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        size.resize(n+1,1);
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
        }
    }
    int p(int x){
        if(parent[x]==x) return parent[x];
        return parent[x]=p(parent[x]); 
    }
    void UR(int u, int v){
         u=p(u);
         v=p(v);
        if(u==v) return;
        if(rank[u]<rank[v]){
            parent[u]=v;
        }
        else if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else {
            parent[u]=v;
            rank[v]++;
        }
    }
    void US(int u, int v){
         u=p(u);
         v=p(v);
        if(u==v) return;
        if(size[u]<size[v]){
            parent[u]=v;
            size[v]+=size[u];
        }
        else if(size[u]>size[v]){
            parent[v]=u;
            size[u]+=size[v];
        }
        else {
            parent[u]=v;
            size[v]+=size[u];
        }
    }
};


class Solution {
private:
    int f(int n, vector<vector<int>>& edges, int skip, vector<int>& force){
        int cost=0;
        int edge_count=0;
        DSU ds(n);
        if(force[0]!=-1){
            ds.US(force[0], force[1]);
            cost+=force[2];
            edge_count++;
        }

        
        for(int i=0;i<edges.size();i++){
            if(edges[i][3]==skip) continue;
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if(ds.p(u)!=ds.p(v)){
                ds.US(u,v);
                cost+=w;
                edge_count++;
            }

        }
        return (edge_count==n-1)?cost:1e9;
        
    }
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        for(int i=0;i<edges.size();i++){
            edges[i].push_back(i);
        }
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] < b[2];
    });
    vector<int>force={-1};
    int mst=f(n,edges,-1,force);
    vector<vector<int>>ans(2);
    for(auto i: edges){
        if(f(n,edges,i[3],force)>mst)
            ans[0].push_back(i[3]);
        else if(f(n,edges,-1,i)==mst)
            ans[1].push_back(i[3]);
    }
    
    return ans;
        

    }
};