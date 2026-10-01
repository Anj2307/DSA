class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int mx=0;
       unordered_set<int>st(nums.begin(),nums.end());
       for(int x: st){
            if(!st.count(x-1)){
                int curr=x;
                int l=1;
                while(st.count(curr+1)){
                    l++;
                    curr++;
                }
                mx=max(l,mx);
            }
       }
       return mx; 
        
    }
};