class Solution { 
public: 
    string repeatLimitedString(string s, int r) { 
        priority_queue<int> p; 
        vector<int> freq(26,0); 
        for(auto i: s){ 
            freq[i-'a']++; 
        } 
        for(int i=0;i<26;i++){ 
            if(freq[i]>0){ 
                p.push(i); 
            } 
        } 
        int prev; 
        bool flag=false; 
        string result=""; 

        while(!p.empty()){ 
            int a=p.top(); 
            p.pop(); 

            if(flag){ 
                
                result+=(a+'a'); 
                freq[a]--; 

                
                p.push(prev); 

                if(freq[a] > 0) {
                    p.push(a);
                }

                flag=false; 
            }else{ 
                if(freq[a]<=r){ 
                    while(freq[a]) { 
                        result+=(a+'a'); 
                        freq[a]--; 
                    } 
                    flag=false; 
                }else{ 
                    for(int i=0;i<r;i++){ 
                        result+=(a+'a'); 
                        freq[a]--; 
                    } 
                    flag=true; 
                    prev=a; 
                } 
            } 
        } 
        return result; 
    } 
};
