//60ms, faster than 76%, mem less than 64%
//hua combined hash table and array, the hash table is val --> vector of indexes in grand array
//    the array is a vector of pairs (val, and its repeat count)  
//this is also the cutting angle, since there is duplicates

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        //add to hash table(m_) and array (vals_)
        m_[val].push_back(vals_.size());
        
        //vals_ array stores val and idx list inside hash table 
        vals_.emplace_back(val, m_[val].size() - 1);
        return m_[val].size() == 1; //1u;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (!m_.count(val)) return false;
        
        //swap with vals_ tail, need to update hash table for the tail
        //remember the grand array vals_ stores val and its index inside hash table
        int index_to_evict = m_[val].back();
        const auto& last_entry = vals_.back();
        
        // Update index
        m_[last_entry.first][last_entry.second] = index_to_evict;
        
        // Swap vals
        swap(vals_.back(), vals_[index_to_evict]);
        
        // remove from both vals_ and m_
        vals_.pop_back();        
        m_[val].pop_back();
        
        if (m_[val].empty()) m_.erase(val);
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vals_[rand() % vals_.size()].first;
    }
private:
    // val -> indices array: indices in vals_
    unordered_map<int, vector<int>> m_;
    // {val, index in the indices array}
    vector<pair<int,int>> vals_;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
