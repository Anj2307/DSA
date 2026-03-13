class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       unordered_map<int,int>m;
       int maxi=0;
       m[0]=-1;
       int sums=0;
       for(int i=0;i<nums.size();i++)
       {
            if(nums[i]==0) sums+=-1;
            else sums+=1;
            if(m.count(sums))
            {
                maxi=max(maxi,i-m[sums]);
            }
            else m[sums]=i;
       }
       return maxi;
         
    }
};