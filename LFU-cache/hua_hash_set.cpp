// huahua use balanced search tree, time O(logCapacity)
// Running time: 120 ms, faster than 95%, mem less than 6%
//shaun read and understand
struct CacheNode {
    int key;
    int value;
    int freq;
    long tick;
    
    // Defines comparison operator or the order, smaller freq will be at front and evicted
    //or freq tied, older timestamp in front
    bool operator <(const CacheNode& right) const {
        if (freq < right.freq) return true;
        if (freq == right.freq) return tick < right.tick;
        return false;
    }
};
class LFUCache {
public:
    LFUCache(int capacity):capacity_(capacity), tick_(0) {}
    
    int get(int key) {
        auto it = m_.find(key);
        if (it == m_.cend()) return -1;
        
        //found CacheNode for the key, 
        int value = it->second.value;
        touch(it->second);
        return value;
    }
    
    void put(int key, int value) {
        if (capacity_ == 0) return; //corner case
        
        auto it = m_.find(key);
        
        if (it != m_.cend()) {
            // Key exists, update value and touch
            it->second.value = value;            
            touch(it->second);            
            return;
        }
        
        if (m_.size() == capacity_) {
            // Remove the first node in balanced search tree(bst) -- cache_, which has
            //   the min freq and oldest timestamp
            const CacheNode& node = *cache_.cbegin();
            m_.erase(node.key); //erase the key value pair from hash
            cache_.erase(node); //erase the CacheNode from bst
        }
        //less than capacity, ready to put into internal data structure
        //construct struct with {p1,p2, ...}
        CacheNode node{key, value, 1, ++tick_};
        //update internal data structure
        m_[node.key] = node;
        cache_.insert(node); // set(tree) insert with copy
    }
private:
    //once a cache node/entry is accessed, what we need to update?
    //timestamp and freq
    void touch(CacheNode& node) {
        cache_.erase(node);     // log(capacity), erase its copy before update       
        ++node.freq; //update 1: freq++
        node.tick = ++tick_; //update 2: tick++
        cache_.insert(node);    // log(capacity), insert copy(updated) into bst 
    }
    
    long tick_;
    int capacity_;
    unordered_map<int, CacheNode> m_;  //hash from key to CacheNode
    set<CacheNode> cache_; //balanced tree of CacheNodes
    
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
