class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            if(m.count(-1*(nums[i]))){
                return {m[-nums[i]],i};
            }else m[nums[i]-target]=i;
        }
        return {0,0};
    }
};