class Solution {

public:
    long long gcdSum(vector<int>& nums) {
        int maxi=nums[0];
        vector<int>vec;
        for(auto it: nums){
            maxi=max(maxi,it);
            vec.push_back(gcd(it,maxi));
        }
        sort(vec.begin(),vec.end());

        long long sum=0;

        for(int i=0;i<(vec.size()/2);i++){

            sum+=(long long)(gcd(vec[i],vec[vec.size()-1-i]));
        }
        return sum;
    }
};