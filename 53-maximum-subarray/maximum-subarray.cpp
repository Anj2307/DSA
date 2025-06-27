class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int total=0;
        int maxi=INT_MIN;
        for(auto i: nums)
        {
            if(total<0)
            total=0;
            
            
                
                total+=i;
                maxi=max(maxi,total);
            
        }
        return maxi;
    }
};