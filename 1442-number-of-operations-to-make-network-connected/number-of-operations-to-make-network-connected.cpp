class DS {
public:
    vector<int> parent, rank;

    DS(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int p(int x){
        if(parent[x]==x) return x;
        return parent[x]=p(parent[x]);
    }

    void unionR(int u,int v){
        u=p(u);
        v=p(v);
        if(u==v) return;

        if(rank[u]<rank[v])
            parent[u]=v;
        else if(rank[u]>rank[v])
            parent[v]=u;
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n-1)
            return -1;

        DS ds(n);

        for(auto &e: connections)
            ds.unionR(e[0], e[1]);

        int comp=0;
        for(int i=0;i<n;i++)
            if(ds.p(i)==i)
                comp++;

        return comp-1;
    }
};