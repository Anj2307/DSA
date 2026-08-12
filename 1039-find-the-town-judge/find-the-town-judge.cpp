class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>indegree(n,0);
        vector<int> outdegree(n,0);
        for(auto &e: trust){
            indegree[e[1]-1]++;
            outdegree[e[0]-1]++;
        }
        int res=-1;
        for(int i=0;i<n;i++){
            if(outdegree[i]==0 && indegree[i]==n-1){
                res=i+1;
            }
        }
        return res;
    }
};