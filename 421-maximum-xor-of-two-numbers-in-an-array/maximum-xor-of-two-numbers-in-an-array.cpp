struct Node{
    Node* link[2]={nullptr};
};
class Trie{
    private: Node* root;
    public:
          Trie()
          {
            root=new Node();
          }
        void insert(int num)
        {
            Node *node=root;
            for(int i=31;i>=0;i--)
            {
                int bit=(num>>i) & 1;
                if(!node->link[bit])
                {
                    node->link[bit]=new Node();
                }
                node=node->link[bit];
            }
        }
        int getMax(int num)
        {
            Node* node= root;
            int maxnum=0;
            for(int i=31;i>=0;i--)
            {
                int bit=(num>>i)&1;
                if(node->link[1-bit]!=nullptr)
                {
                   maxnum=maxnum |(1<<i);
                   node=node->link[1-bit];
                }
                else{
                        node=node->link[bit];
                }
            }
            return maxnum;
        }

};






class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto i: nums)
        {
            trie.insert(i);
        }
        int maxnum=0;
        for(auto i: nums)
        {
            maxnum=max(trie.getMax(i),maxnum);
        }
        return maxnum;
    }
};