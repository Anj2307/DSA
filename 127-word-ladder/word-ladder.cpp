class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>set(wordList.begin(),wordList.end());
        if(!set.count(endWord)) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            pair<string,int>p=q.front();q.pop();
            for(int i=0;i<p.first.length();i++)
            {
                for(char j='a';j<='z';j++)
                {
                    string test=p.first;
                    test[i]=j;
                    if(test==endWord)
                    return p.second+1;
                    if(set.count(test))
                    {
                      q.push({test,p.second+1});
                      set.erase(test);
                    }
                }
            }
        }
        return 0;
    }
};