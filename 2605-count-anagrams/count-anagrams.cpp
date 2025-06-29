class Solution {
private:
    const int MOD = 1e9 + 7;

    long long modinv(long long a) {
        long long res = 1, b = MOD - 2;
        while (b) {
            if (b & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return res;
    }

    int anagram(int count, unordered_map<char, int>& map, vector<long long>& fact) {
        long long p = fact[count];
        for (auto& pair : map) {
            p = (p * modinv(fact[pair.second])) % MOD;
        }
        return p;
    }

public:
    int countAnagrams(string s) {
        int n = s.length();
        vector<long long> fact(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        int count = 0;
        int res = 1;
        unordered_map<char, int> map;

        for (int i = 0; i <= n; i++) {
            if (i < n && s[i] != ' ') {
                map[s[i]]++;
                count++;
            } else {
                if (count > 0) {
                    res = (1LL * res * anagram(count, map, fact)) % MOD;
                    count = 0;
                    map.clear();
                }
            }
        }

        return res;
    }
};
