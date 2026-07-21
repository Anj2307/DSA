class DS{
public:

    vector<int> parent, rank,size;

    DS(int n) {
        parent.resize(n);
        rank.resize(n,0);
        size.resize(n);
        for(int i=0;i<n;i++){
             parent[i]=i;
             size[i]=1;
        }
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

    void unionS(int u, int v){

        u=p(u);
        v=p(v);

        if(u==v) return;
        if(size[u]<size[v]){
            parent[u]=v;
            size[v]+=size[u];
        }
        else {
            parent[v]=u;
            size[u]+=size[v];
        }
    }
};
class Solution {
private:
    bool valid(int adjr,int adjc, int n){
        if(adjr<0||adjc<0||adjr>=n||adjc>=n) return false;
        return true;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {

        int n=grid.size();
        DS ds(n*n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                for(int k=0;k<4;k++){
                    int adjr= i+dr[k];
                    int adjc=j+dc[k];
                    if(valid(adjr,adjc,n) && grid[adjr][adjc]==1){
                        int node=i*n+j;
                        int adj=adjr*n+adjc;
                        ds.unionS(node,adj);
                    }
                }
            }
        }
        int mx=0;
        

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                set<int> comp;
                for(int k=0;k<4;k++){
                    int adjr=i+dr[k];
                    int adjc=j+dc[k];
                    if(valid(adjr,adjc,n) && grid[adjr][adjc]==1){
                        comp.insert(ds.p(adjr*n+adjc));
                    }
                }
                int total=0;
                for(auto it: comp){
                    total+=ds.size[it];
                }
                mx=max(mx,total+1);
            }
        }

        for(int i=0;i<n;i++){
            mx=max(mx,ds.size[ds.p(i)]);
        }
        return mx;
        

        
        
        

        
    }
};