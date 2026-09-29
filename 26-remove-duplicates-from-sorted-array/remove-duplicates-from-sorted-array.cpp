class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int curr=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==curr){
                nums[i]=1e8;
                n--;
            }else curr=nums[i];
        }
        sort(nums.begin(),nums.end());
        return n;
    }
};