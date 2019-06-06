// hua use CacheNode, hash and doubly linked list
// Running time: 108 ms, faster than 99%, mem less than 92%
//shaun has read and understand
struct CacheNode {
    int key;
    int value;
    int freq;
    // pointer to the node in the list
    list<int>::iterator it;
    //list<int>::const_iterator it; //okay too, remember init with list1.cbegin()
};
 
class LFUCache {
public:
    LFUCache(int capacity): capacity_(capacity), min_freq_(0) {}
    
    int get(int key) {
        auto it = n_.find(key);
        if (it == n_.cend()) return -1;
        
        //found key and CacheNode
        //update it the CacheNode freq and list
        touch(it->second);
        return it->second.value;
    }
    
    void put(int key, int value) {
        if (capacity_ == 0) return; //corner case
        
        auto it = n_.find(key);
        if (it != n_.cend()) {
            // Key already exists, update the value and touch it
            it->second.value = value;
            touch(it->second);
            return;
        }
        
        if (n_.size() == capacity_) {
            // No capacity, need to remove one entry that
            // 1. has the min freq
            // 2. least recently used if there are multiple ones, back of the list
            
            // Step 1: remove the element from min_freq_ list
            const int key_to_evict = l_[min_freq_].back();
            l_[min_freq_].pop_back();
            
            // Step 2: erase the key from hashmap of key to CacheNode
            n_.erase(key_to_evict);
        }
        
        //at this point, it is a new key
        // We know new item has freq of 1, thus set min_freq to 1
        const int freq = 1;
        min_freq_ = freq;
        
        // Add the key to the freq list, latest to front, so oldest at back
        l_[freq].push_front(key);
        
        // Create a new node and insert into the hash map
        n_[key] = {key, value, freq, l_[freq].begin()};
    }
private:
    void touch(CacheNode& node) {
        // Step 1: update the frequency
        const int prev_freq = node.freq;
        const int freq = ++(node.freq);
        
        // Step 2: erase the entry(freq and its list of keys) from old freq list with list::iterator stored in CacheNode
        l_[prev_freq].erase(node.it);
        
        if (l_[prev_freq].empty() && prev_freq == min_freq_) {
            // no longer has prev_freq, Delete its  list
            l_.erase(prev_freq);
            
            // Increase the min freq
            ++min_freq_;
        }
        
        // Step 4: insert the key into the front of the new freq list
        l_[freq].push_front(node.key);
        
        // Step 5: update the pointer
        node.it = l_[freq].begin();
    }
    
    int capacity_;
    int min_freq_;
    
    // map from key -> CacheNode
    unordered_map<int, CacheNode> n_;
    
    // freq -> list
    unordered_map<int, list<int>> l_;
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
