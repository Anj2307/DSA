class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        s += " "; 
        
        int i=0;
        unordered_map<string,char>map;
        unordered_set<char>set;
        stack<string>str;
        string word="";
        
        for(int j=0;j<s.length();j++)
        {
            if(s[j]==' ')
            {
                
                if (i >= pattern.length()) return false; 

                if(!map.count(word)&&!set.count(pattern[i]))
                {
                    map[word]=pattern[i];
                    set.insert(pattern[i]);
                    i++;
                    word="";
                }
               else if(map.count(word)&&!set.count(pattern[i]))
                {
                    return false;
                }
               else if(map.count(word)&&set.count(pattern[i]))
                {
                    if(map[word]==pattern[i]){
                        set.insert(pattern[i]);
                        i++;
                        word="";
                    }
                    else
                    return false;
                }
               else if(!map.count(word)&&set.count(pattern[i]))
                return false;
            }
           else word+=s[j];
        }
        
        
        return i == pattern.length(); 
    }
};
