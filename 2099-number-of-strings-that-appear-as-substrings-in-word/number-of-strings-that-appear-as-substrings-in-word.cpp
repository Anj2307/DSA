class Solution {
private:
    bool check(string& str, string word){
        if(str.length()>word.length()) return false;
        if(word.find(str)!=-1) return true;
        else return false;
    }
public:

    int numOfStrings(vector<string>& patterns, string word) {
        int n=0;
        for(auto i: patterns){
            if(check(i,word)) n++;
        }
        return n;
    }
};