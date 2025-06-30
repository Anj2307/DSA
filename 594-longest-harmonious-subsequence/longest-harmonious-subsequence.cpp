class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>map;
        unordered_set<int>set;
        for(auto i: nums)
        {
            map[i]++;
            set.insert(i);
        }
        int m=0;
        for(auto i: set)
        {
            if(map[i+1]==0) continue;
            m=max(m,map[i]+map[i+1]);
        }
        return m;
    }
};