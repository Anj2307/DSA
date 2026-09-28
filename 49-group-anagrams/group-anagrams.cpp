class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>vec;
        unordered_map<string,vector<string>> m;
        for(auto i: strs){
            string p=i;
            sort(p.begin(),p.end());
            m[p].push_back(i);
        }
        for(auto it: m){
            vec.push_back(it.second);
        }
        return vec;
    }
};