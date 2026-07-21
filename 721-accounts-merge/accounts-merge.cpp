#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class DS { 
public: 
    vector<int> parent, rank; 
    DS(int n) { 
        parent.resize(n); 
        rank.resize(n, 0); 
        for(int i = 0; i < n; i++) parent[i] = i; 
    } 
    int p(int x) { 
        if(parent[x] == x) return x; 
        return parent[x] = p(parent[x]); 
    } 
    void unionR(int u, int v) { 
        u = p(u); 
        v = p(v); 
        if(u == v) return; 
        if(rank[u] < rank[v]) parent[u] = v; 
        else if(rank[u] > rank[v]) parent[v] = u; 
        else { 
            parent[v] = u; 
            rank[u]++; 
        } 
    } 
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        DS ds(accounts.size());
        unordered_map<string, int> l;
        
        for(int j = 0; j < accounts.size(); j++) {
            for(int i = 1; i < accounts[j].size(); i++) {
                if(l.count(accounts[j][i])) {
                    ds.unionR(j, l[accounts[j][i]]);
                } else {
                    l[accounts[j][i]] = j;
                }
            }
        }
        
        map<int, set<string>> m;
        for(auto& pair : l) {
            m[ds.p(pair.second)].insert(pair.first);
        }
        
        vector<vector<string>> result;
        for(auto& pair : m) {
            vector<string> component;
            component.push_back(accounts[pair.first][0]);
            component.insert(component.end(), pair.second.begin(), pair.second.end());
            result.push_back(component);
        }
        
        return result;
    }
};
