class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int maxXOR = 0;
        for(int i = 0; i < nums.size() - 1; i++){            
            for(int j = i + 1; j < nums.size(); j++){
                if(abs(nums[i] - nums[j]) <= min(nums[i], nums[j])){
                    maxXOR = max(maxXOR, nums[i] ^ nums[j]);
                }
            }
        }
        return maxXOR;
    }
};