class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int so=intervals[0][0];
        int sc=intervals[0][1];
        vector<vector<int>>vec;
        for(int i=1;i<intervals.size();i++){
            if(so==intervals[i][0] && sc<intervals[i][1]){
                so=intervals[i][0];
                sc=intervals[i][1];
            }else if(intervals[i][0]<=sc){
                if(intervals[i][1]>sc){
                    sc=intervals[i][1];
                }
            }else if(intervals[i][0]>sc){
                vec.push_back({so,sc});
                so=intervals[i][0];
                sc=intervals[i][1];
            }
        }
        cout<<so<<sc;
        vec.push_back({so,sc});
        return vec;
    }
};