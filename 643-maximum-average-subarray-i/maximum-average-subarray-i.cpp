class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double mx=INT_MIN;
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=static_cast<double>(nums[i]);
        }
        mx=sum/k;
        for(int i=k;i<nums.size();i++){
            sum-=static_cast<double>(nums[i-k]);
            sum+=static_cast<double>(nums[i]);
            mx=max(mx,sum/k);
        }
        return mx;
    }
};