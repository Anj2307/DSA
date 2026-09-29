class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        int m=*min_element(ranks.begin(),ranks.end());
        long long high=m*cars;
        high*=cars;
        long long low=1;
        long long ans=high;
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long t=0;
            for(int i: ranks){
                t+=sqrt((mid/i));
            }
            if(t>=cars){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }

        }
        return ans;
    }
};