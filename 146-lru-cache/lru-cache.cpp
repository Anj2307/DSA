class LRUCache {
private:
    int cap;
    long long timestamp;
    typedef pair<long long, int>c;
    unordered_map<int, c> cache;
    priority_queue<c,vector<c>,greater<c>> m_h;
public:
    LRUCache(int capacity) {
        cap=capacity;
        timestamp=0;
    }
    
    int get(int key) {
        if(!cache.count(key)) return -1;
        timestamp++;
        cache[key].first=timestamp;
        m_h.push({timestamp,key});
        return cache[key].second;
    }
    
    void put(int key, int value) {
        timestamp++;
       if(cache.count(key)){
            cache[key]={timestamp,value};
            m_h.push({timestamp,key});
            return;
       } 
       if(cache.size()==cap){
            while(!m_h.empty()){
                c top=m_h.top();
                long long time=top.first;
                int k=top.second;
                m_h.pop();

                if(cache.count(k) && cache[k].first==time){
                    cache.erase(k);
                    break;
                }
            }
       }
       cache[key]={timestamp,value};
       m_h.push({timestamp,key});

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */