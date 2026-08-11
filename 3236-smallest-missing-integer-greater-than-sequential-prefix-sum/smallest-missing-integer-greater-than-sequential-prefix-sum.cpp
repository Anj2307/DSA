class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans=0;
        ans+=nums[0];
        if(nums.size()==1) return nums[0]+1;
        bool flag=false;
        int check=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=nums[i-1]+1 && !flag){
                flag=true;
                sort(nums.begin()+i,nums.end());
                check=ans;
                if(i==1)    check++;
            }
            if(!flag){
                ans+= nums[i];
            }
            if(flag){
                if(nums[i]==check)
                    check++;
                
            }
        }
        if(flag==false) return ans;
        return check;
   }
};