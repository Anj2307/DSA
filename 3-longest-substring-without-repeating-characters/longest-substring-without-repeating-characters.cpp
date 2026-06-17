class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int left = 0, right = 0;
        int res = 0;

        while (right < s.length()) {
            if (!set.count(s[right])) {
                set.insert(s[right]);
                res = max(res, right - left + 1);
                right++;
            } else {
                set.erase(s[left]);
                left++;
            }
        }

        return res;
    }
};