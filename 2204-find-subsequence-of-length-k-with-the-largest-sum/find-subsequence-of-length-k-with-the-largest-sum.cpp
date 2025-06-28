class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int>pq(nums.begin(),nums.end());
        unordered_map<int,int>map;
        for(int i=0;i<k;i++)
        {
            int val=pq.top();pq.pop();
            if(!map.count(val)) map.insert({val,1});
            else map[val]++;
        }
        vector<int>res;
        for(auto i: nums)
        {
            if(map[i]>0)
            {
                res.push_back(i);
                map[i]--;
            }
        }
        return res;
    }
};