class Solution {
public:
    string predictPartyVictory(string senete) {
        queue<int>r;
        queue<int>d;
        int n=senete.size();
        for(int i=0;i<senete.size();i++){
            if(senete[i]=='R')
                r.push(i);
            else d.push(i);
        }
        while(!r.empty() && !d.empty()) {
            int r_idx = r.front(); r.pop();
            int d_idx = d.front(); d.pop();
            
            
            if(r_idx < d_idx) {
                r.push(r_idx + n);
            } else {
                d.push(d_idx + n);
            }
        }
        
        return r.empty() ? "Dire" : "Radiant";
    }
    
};