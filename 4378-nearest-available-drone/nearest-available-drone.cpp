class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int mi=1e9;
        int idx=-1;
        for(int i=0;i<drones.size();i++){
            if(abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1])<=drones[i][2]){
                if(mi>abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]))
                {
                    idx=i;
                    mi=abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]);
                }
            }
        }
        return idx;
    }
};