class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int>map;
        for(char i: text)
        {
            map[i]++;
        }
        int c=1e07;
        c=min(c,map['b']);
        c=min(c,map['a']);
        c=min(c,map['l']/2);
        c=min(c,map['o']/2);
        c=min(c,map['n']);
        return c;
    }
};