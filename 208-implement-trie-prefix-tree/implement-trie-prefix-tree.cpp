struct Node{
    Node *links[26];
    bool flag=false;
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }

    bool setend()
    {
       return  flag=true;
    }
    bool isEnd()
    {
        return flag;
    }
};




class Trie {
    private: Node* root;

public:
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
        for(int i=0;i<word.length();i++)
        {
          if(!node->containsKey(word[i]))
          {
            node->put(word[i],new Node());
          }
         // moves to the new reference track
          node=node->get(word[i]);
        }
        node->setend();
    }
    
    bool search(string word) {
        Node *node =root;
        for(auto i:word)
        {
            if(!node->containsKey(i))
            return false;
            node=node->get(i);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
        for(auto i: prefix)
        {
            if(!node->containsKey(i))
            return false;
            node=node->get(i);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */