class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arr) {
        int mx=*max_element(lights.begin(),lights.end());
        int ans=0;
        for(int i=0;i<arr.size();i++){
            arr[i]=arr[i] % period;
            if(arr[i]>= mx){
                ans=max(ans,period-arr[i]);
            }
        }
        return ans;





    }
};