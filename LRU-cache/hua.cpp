/*
Runtime: 128 ms, faster than 94.76% of C++ online submissions for LRU Cache.
Memory Usage: 38.2 MB, less than 57.39% of C++ online submissions for LRU Cache.
both grandyang and huahua use this approach
easier to remember
*/
class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        const auto it = m_.find(key);
        // If key does not exist
        if (it == m_.cend()) return -1;
 
        // Move this key to the front of the cache
        cache_.splice(cache_.begin(), cache_, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {        
        const auto it = m_.find(key);
        
        // Key already exists
        if (it != m_.cend()) {
            // Update the value it->first is key, it->second is val
            //val is list iterator of pairs it->second->second
            it->second->second = value;
            // Move this entry it->second to the front of the cache
            cache_.splice(cache_.begin(), cache_, it->second);
            return;
        }
        
        // Reached the capacity, remove the oldest entry, from both m and cache
        if (cache_.size() == capacity_) {
            const auto& node = cache_.back();
            m_.erase(node.first); //remove the key 
            cache_.pop_back(); //remove last element
        }
        
        // Insert the entry to the front of the cache and update mapping.
        cache_.emplace_front(key, value); //insert a new element at beginging of list
        m_[key] = cache_.begin(); //key to its list of pair iterator
    }
private:
    int capacity_;
    list<pair<int,int>> cache_;
    unordered_map<int, list<pair<int,int>>::iterator> m_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
