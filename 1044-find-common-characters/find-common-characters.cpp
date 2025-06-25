class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
         vector<string>vec;
         unordered_map<char,int>map;
         for(auto i: words[0])
         {
            map[i]++;
         }
         for(int i=1;i<words.size();i++)
         {
            unordered_map<char,int>unit;
            for(int j=0;j<words[i].size();j++)
            {
                unit[words[i][j]]++;
            }
            for(auto& p:map)
            {
                if(!unit.count(p.first)) map[p.first]=0;
                else{
                    map[p.first]=min(unit[p.first],p.second);
                }
            }

         }
         for(auto &p:map)
         {
            for(int i=0;i<p.second;i++)
            {
                vec.push_back(string(1, p.first));
            }
         }
         return vec;
    }
};