class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int base = 0;
        for (char c : s)
            if (c == '1') base++;

        string t = "1" + s + "1";

        vector<pair<char,int>> runs;
        int i = 0, m = t.size();

        while (i < m) {
            int j = i;
            while (j < m && t[j] == t[i]) j++;
            runs.push_back({t[i], j - i});
            i = j;
        }

        int gain = 0;

        for (int i = 1; i + 1 < (int)runs.size(); i++) {
            if (runs[i].first == '1' &&
                runs[i - 1].first == '0' &&
                runs[i + 1].first == '0') {

                gain = max(gain, runs[i - 1].second + runs[i + 1].second);
            }
        }

        return base + gain;
    }
};