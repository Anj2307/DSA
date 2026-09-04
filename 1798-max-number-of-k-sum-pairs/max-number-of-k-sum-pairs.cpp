class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        int r=nums.size()-1;
        int j=0;
        while(l<r){
            if(nums[l]+nums[r]==k)
                {
                    l++;
                    r--;
                    j++;
                }
            else if(nums[l]+nums[r]>k){
                r--;
            }else l++;
        }
        return j;
    }
};