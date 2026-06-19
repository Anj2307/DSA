class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int m=0;
        int res=0;
        for(int i=0;i<gain.size();i++)
        {
            m+=gain[i];
            res=max(res,m);
        }
        return res;
    }
};