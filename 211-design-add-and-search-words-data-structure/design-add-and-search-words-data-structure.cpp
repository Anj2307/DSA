struct Node{
    Node* links[26]={nullptr};
    bool flag=false;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node *node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    void set()
    {
        flag=true;
    }


};

class WordDictionary {
    private: Node *root;
public:
    WordDictionary() {
        root= new Node();
    }
    
    void addWord(string word) {
        Node* node=root;
        for(auto i:word){
       if(!(node->containsKey(i)))
       {
        node->put(i,new Node);
       }
       node=node->get(i);
        }
       node->set();
    }
    
    bool search(string word) {
       
      queue<pair<Node*,int>> q;
      q.push({root,0});
           
      while(!q.empty())
      {
        auto [node,idx]=q.front();
        q.pop();
        if(idx==word.size())
        {
            if(node->flag) return true;
            continue;
        }
        char ch=word[idx];
        if(ch=='.')
        {
            for(int i=0;i<26;i++)
            {
                if(node->links[i])
                {
                    q.push({node->links[i],idx+1});

                }
            }
        }
        else {
            if(node->containsKey(ch))
            {
                q.push({node->get(ch),idx+1});
            }
        }
      }
        return false;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */