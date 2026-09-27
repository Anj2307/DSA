class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.rbegin(), inventory.rend());
        int q = 0;
        long long sum = 0; 
        long long mod = 1000000007; 
        long long count = 1; 

        while (orders > 0) {
            long long next_val = (q == inventory.size() - 1) ? 0 : inventory[q + 1];
            long long p = inventory[q] - next_val;
            long long total_available = p * count;

            if (total_available >= orders) {
                long long full_rows = orders / count;
                long long remainder = orders % count;
                long long top_val = inventory[q];
                long long bottom_val = inventory[q] - full_rows;
                long long sum_rows = (top_val + bottom_val + 1) * full_rows / 2;
                
                sum = (sum + (sum_rows % mod) * count) % mod;
                sum = (sum + remainder * bottom_val) % mod;
                return sum;
            } else {
                long long top_val = inventory[q];
                long long bottom_val = next_val;
                long long sum_rows = (top_val + bottom_val + 1) * p / 2;
                
                sum = (sum + (sum_rows % mod) * count) % mod;
                orders -= total_available;
                q = q + 1;
                count = count + 1; 
            }
        }
        return sum;
    }
};
