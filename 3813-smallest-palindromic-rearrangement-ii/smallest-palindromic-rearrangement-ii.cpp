class Solution {
private:
    long long count1(int l, const map<char, int>& m, long long mx) {
        if (l == 0) return 1;
        vector<int> cnts;
        for (auto const &[ch, count] : m) {
            if (count > 0) cnts.push_back(count);
        }
        long long total = 1;
        int curr = 1;
        for (int c : cnts) {
            for (int j = 1; j <= c; ++j) {
                total *= curr++;
                total /= j;
                if (total > mx) return mx + 1;
            }
        }
        while (curr <= l) {
            total *= curr++;
            if (total > mx) return mx + 1;
        }
        return total;
    }

public:
    string smallestPalindrome(string s, int k) {
        vector<int> vec(26, 0);
        for (int i = 0; i < s.length(); i++) {
            vec[s[i] - 'a']++;
        }
        string left = "";
        string middle = "";
        for (int i = 0; i < 26; i++) {
            if (vec[i] == 0) continue;
            int n = vec[i] / 2;
            for (int j = 0; j < n; j++) {
                left += (char)(i + 'a');
            }
            if (vec[i] % 2 == 1) middle += (char)(i + 'a');
        }
        if (middle.length() > 1) return "";
        map<char, int> m;
        for (auto i : left) {
            m[i]++;
        }
        long long tk = k;
        long long total = count1(left.length(), m, tk);
        if (tk > total) return "";
        string result = "";
        int n = left.length();
        for (int i = 0; i < left.length(); ++i) {
            for (auto &[ch, count] : m) {
                if (count == 0) continue;
                m[ch]--;
                long long pc = count1(n - 1 - i, m, tk);
                if (tk > pc) {
                    tk -= pc;
                    m[ch]++;
                } else {
                    result += ch;
                    break;
                }
            }
        }
        string right = result;
        reverse(right.begin(), right.end());
        return result + middle + right;
    }
};
