class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int l=0;
        int r=0;
        int mx=0;
        int curr=0;
        for(r=0;r<nums.size();r++){
            if(nums[r]==0)
                curr++;
            while(curr>k){
                if(nums[l]==0)
                    curr--;
                l++;
            }
            mx=max(mx,r-l+1);
        }
        return mx;
        
    }
};