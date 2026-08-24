class Solution {
public:
    vector<string>ans;
    bool valid(string &s){
        if(s.size()>1 && s[0]=='0')
            return false;
        return stoi(s)<=255;
    }

    void dfs(string &s, int idx, int parts, string cur){
        if(parts ==4){
            if(idx==s.size()){
                cur.pop_back();
                ans.push_back(cur);
            }
            return;
        }
        for(int len=1;len<=4;len++){
            if(idx+len>s.size())
            break;
            string segment=s.substr(idx,len);
            if(!valid(segment))
                continue;
            dfs(s,idx+len,parts+1,cur+segment+".");
        }
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(s,0,0,"");
        return ans;
    }
};