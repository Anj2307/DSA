class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) return res;

        int wordLen = words[0].length();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        unordered_map<string, int> wordMap;
        for (string word : words) {
            wordMap[word]++;
        }

        for (int i = 0; i < wordLen; i++) {  // We need to try from every offset within word length
            int left = i, count = 0;
            unordered_map<string, int> windowMap;

            for (int j = i; j + wordLen <= s.length(); j += wordLen) {
                string word = s.substr(j, wordLen);
                if (wordMap.count(word)) {
                    windowMap[word]++;
                    count++;

                    // If word occurs more than needed, shrink the window
                    while (windowMap[word] > wordMap[word]) {
                        string leftWord = s.substr(left, wordLen);
                        windowMap[leftWord]--;
                        left += wordLen;
                        count--;
                    }

                    if (count == wordCount) {
                        res.push_back(left);
                    }
                } else {
                    // Reset everything if the word is not part of words
                    windowMap.clear();
                    count = 0;
                    left = j + wordLen;
                }
            }
        }

        return res;
    }
};
