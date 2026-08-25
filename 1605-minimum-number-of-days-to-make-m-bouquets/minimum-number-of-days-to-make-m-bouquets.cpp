class Solution {
private:
    bool possible(vector<int>& bloomday, int m , int k, int day){
        int cnt=0;
        int bonquet=0;
        for(int &i: bloomday){
            if(i<=day){
                cnt++;
                if(cnt==k){
                    bonquet++;
                    cnt=0;
                }
            }else{
                cnt=0;
            }
        }
        return bonquet>=m;
    }
public:
    int minDays(vector<int>& bloomday, int m, int k) {
        if((long long)bloomday.size()<1LL*m*k) return -1;
        int l=*min_element(bloomday.begin(),bloomday.end());
        int r=*max_element(bloomday.begin(),bloomday.end());
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(bloomday,m,k,mid)){
                ans=mid;
                r=mid-1;
            }else {
                l=mid+1;
            }
        }
        return ans;
    }
};