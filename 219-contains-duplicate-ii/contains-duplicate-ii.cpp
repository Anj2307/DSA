class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>p;
        for(int i=0;i<nums.size();i++)
        {
            if(p.count(nums[i]))
            {
                if(i-p[nums[i]]<=k) return true;
                else p[nums[i]]=i;
            }
            else p.insert({nums[i],i});
        }
        return false;
    }
};