class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int l=0;
        int mx=0;
        for(int r=0;r<nums.size();r++){
            m[nums[r]]++;
            if(m[nums[r]]<=k)
                mx=max(mx,r-l+1);
            if(m[nums[r]]>k){
                while(m[nums[r]]>k){
                    m[nums[l]]--;
                    l++;
                }
            }
        }
        return mx;
    }
};