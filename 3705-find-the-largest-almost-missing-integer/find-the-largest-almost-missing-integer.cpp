class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> m;
        for (int num : nums) {
            m[num]++;
        }

        if (k == n) {
            int max_val = -1;
            for (int num : nums) {
                max_val = max(max_val, num);
            }
            return max_val;
        }

        if (k == 1) {
            int max_val = -1;
            for (int num : nums) {
                if (m[num] == 1) {
                    max_val = max(max_val, num);
                }
            }
            return max_val;
        }

        int ans = -1;
        if (m[nums[0]] == 1) ans = max(ans, nums[0]);
        if (m[nums[n - 1]] == 1) ans = max(ans, nums[n - 1]);
        
        return ans;
    }
};
