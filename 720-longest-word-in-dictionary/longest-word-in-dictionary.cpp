struct Node{
    Node* link[26]={nullptr};
    bool flag=false;
};
class Trie{
    private: Node* root;
    public:
     Trie(){
        root=new Node();
     }
     void insert(string word)
     {
        Node *node = root;
        for(auto i: word)
        {
            if(!node->link[i-'a'])
            node->link[i-'a']=new Node();
            node=node->link[i-'a'];
        }
        node->flag=true;
     }
     int search(string word)
     {
        Node *node=root;
        int count=0;
        for(auto i: word)
        {
           if(!node->link[i-'a'] || node->link[i-'a']->flag == false)
           break;
           node = node->link[i-'a'];
           count++;

          
        }
        return count;
     }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;
        pair<string,int>p;
        sort(words.begin(),words.end());
        for(auto i: words)
        {
            trie.insert(i);
        }
        p.second=INT_MIN;
        p.first="";
        for(auto i: words)
        {
            if(p.second<trie.search(i))
            {
                p.second=trie.search(i);
                p.first=i;
            }
        }
        return (p.second>0)?p.first:"";
        
    }
};