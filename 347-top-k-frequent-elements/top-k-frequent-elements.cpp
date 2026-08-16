class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        priority_queue<pair<int,int>>q;
        for(auto n: nums){
            m[n]++;
        }
       for(auto &p: m){
        q.push({p.second,p.first});
       }
       vector<int>vec;
       for(int i=0;i<k;i++){
        vec.push_back(q.top().second);
        q.pop();
       }
       return vec;
    }
};