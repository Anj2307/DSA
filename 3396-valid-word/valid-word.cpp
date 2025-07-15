class Solution {
public:
    bool isValid(string word) {
        if(word.length()<3) return false;
        unordered_set<char>set;
        bool vovel=false;
        bool cons=false;
        set.insert({'a','e','i','o','u'});
        for(int i=0;i<word.length();i++)
        {
            if(!isalnum(word[i])) return false;
            if(word[i]>='0'&& word[i]<='9') continue;
            if(set.count(tolower(word[i]))) vovel=true;
            else cons=true;
        }
        if(vovel&&cons) return true;
        return false;
    }
};