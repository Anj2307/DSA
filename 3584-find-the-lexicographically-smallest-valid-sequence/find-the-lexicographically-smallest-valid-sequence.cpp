class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        vector<int> last(n2, -1);
        
        int i = n1 - 1, j = n2 - 1;
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }
        
        vector<int> ans;
        bool changed = false;
        j = 0;
        
        for (i = 0; i < n1; ++i) {
            if (j == n2) break;
            
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (!changed) {
                if (j + 1 == n2 || (last[j + 1] != -1 && last[j + 1] > i)) {
                    ans.push_back(i);
                    changed = true;
                    j++;
                }
            }
        }
        
        return ans.size() == n2 ? ans : vector<int>();
    }
};
