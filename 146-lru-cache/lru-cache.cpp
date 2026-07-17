#include <unordered_map>
#include <queue>
#include <vector>

class LRUCache {
private:
    int cap;
    long long timestamp; 
    
    // Maps: key -> pair<value, timestamp_when_last_used>
    std::unordered_map<int, std::pair<int, long long>> cache;
    
    // Min-heap: stores pair<timestamp, key> to easily find the oldest item
    std::priority_queue<std::pair<long long, int>, 
                        std::vector<std::pair<long long, int>>, 
                        std::greater<std::pair<long long, int>>> min_heap;

public:
    LRUCache(int capacity) {
        cap = capacity;
        timestamp = 0;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        // Increment timestamp and update the key's last used time
        timestamp++;
        cache[key].second = timestamp;
        
        // Push the new timestamp state to the heap
        min_heap.push({timestamp, key});
        
        return cache[key].first;
    }
    
    void put(int key, int value) {
        timestamp++;
        
        // Case 1: Key already exists, just update value and timestamp
        if (cache.find(key) != cache.end()) { 
            cache[key] = {value, timestamp};
            min_heap.push({timestamp, key});
            return;
        }
        
        // Case 2: Cache is full, perform lazy eviction
        if (cache.size() == cap) {
            while (!min_heap.empty()) {
                std::pair<long long, int> top_element = min_heap.top();
                long long time = top_element.first;
                int k = top_element.second;
                min_heap.pop();
                
                // Evict only if this timestamp matches the current valid timestamp in the map
                if (cache.find(k) != cache.end() && cache[k].second == time) {
                    cache.erase(k);
                    break;
                }
            }
        }
        
        // Insert the new key-value pair
        cache[key] = {value, timestamp};
        min_heap.push({timestamp, key});
    }
};
