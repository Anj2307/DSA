class Solution {
public:
    int minimumPushes(string word) {
        priority_queue<pair<int,char>>p;
        unordered_map<char,int>w;
        for(auto i: word){
            if(!w.count(i))
                w[i]=1;
            else w[i]++;
        }
        for(auto  it: w){
            p.push({it.second,it.first});
        }
        int curr=1;
        int no=2;
        int ans=0;
        while(!p.empty()){
            auto e=p.top(); p.pop();
            if(no==10){
                no=2;
                curr++;
            }
            ans+=e.first*curr;
            no++;
        }
        return ans;
    }
};