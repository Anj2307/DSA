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
                int bit=(num>>i) & 1;
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& qu) {
        Trie trie;
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> q;
        for(int i=0;i<qu.size();i++)
        {
            q.push_back({qu[i][1],{qu[i][0],i}});
        }
        sort(q.begin(),q.end());
        vector<int>ans(qu.size(), -1);
        int idx=0;
        for(int i=0;i<qu.size();i++)
        {
            int mi=q[i].first;
            int xi=q[i].second.first;
           while (idx < nums.size() && nums[idx] <= mi) {
                trie.insert(nums[idx]);
                idx++;
            }

            
            if (idx > 0) {
                ans[q[i].second.second] = trie.getMax(xi);
            }
        }

        return ans;
    }
            
    
};