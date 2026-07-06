class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        vector<bool>vec(intervals.size(),true);
        int sum=0;
        for(int i=0;i<intervals.size();i++){
            for(int j=0;j<intervals.size();j++)
            {
                if(i!=j && vec[i]&& vec[j]){
                    if(intervals[i][0]>=intervals[j][0] && intervals[i][1]<=intervals[j][1])
                    {
                        vec[i]=false;
                        sum++;
                    }
                }
            }
        }

        return intervals.size()-sum;
           

    }
};