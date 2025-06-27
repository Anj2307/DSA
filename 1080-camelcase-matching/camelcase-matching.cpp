struct Node {
    unordered_map<char, Node*> map;
    bool flag = false;

    void put(char ch, Node* node) {
        map[ch] = node;
    }

    bool contains(char ch) {
        return map.count(ch) > 0;
    }

    Node* get(char ch) {
        return map[ch];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->contains(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->flag = true;
    }

    
    bool search(const string& query) {
        Node* node = root;
        int i = 0; 

        while (i < query.size()) {
            char ch = query[i];

           
            if (islower(ch)) {
                if (node->contains(ch)) {
                    node = node->get(ch);
                }
                i++;
            }
           
            else {
                if (!node->contains(ch))
                    return false;
                node = node->get(ch);
                i++;
            }
        }

        
        while (node && !node->flag && !node->map.empty()) {
           return false;
        }

        return node && node->flag;
    }
};

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        Trie trie;
        trie.insert(pattern);
        vector<bool> result;

        for (string& q : queries) {
            result.push_back(trie.search(q));
        }

        return result;
    }
};
