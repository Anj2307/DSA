class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> ans;
        vector<int> count(10, 0);
        for (int d : digits)
            count[d]++;

        // Build numbers abc
        for (int a = 1; a <= 9; ++a) {
            for (int b = 0; b <= 9; ++b) {
                for (int c = 0; c <= 8; c += 2) {
                    // Check available digits
                    if (count[a] > 0
                        && count[b] > (b == a ? 1 : 0)
                        && count[c] > (c == a ? 1 : 0) + (c == b ? 1 : 0)) {
                        ans.push_back(a * 100 + b * 10 + c);
                    }
                }
            }
        }
        return ans;
    }
};
