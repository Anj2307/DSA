class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int mx=0;
        int e_m=-1e9;
        for(auto n: nums){
            sum+=n;
            mx=max(sum,mx);
            if(sum<0){
                sum=0;
            }
            e_m=max(n,e_m);

        }
        
        if(mx==0) return e_m;
        else return mx;
    }
};