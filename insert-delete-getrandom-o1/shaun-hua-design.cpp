//hua design combine hash map and array 
//hash map to support O1 insert and delete, array to support random access
//cutting angle === combine hash map and dynamic array,  remove --->  for the array, swap with tail 
//runtime 52ms, faster than 91%, mem less than 72%
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m_.count(val)) return false;
        m_[val] = vals_.size();
        vals_.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!m_.count(val)) return false;
        // val        vals.back()
        // index        ?
        int index = m_[val];
        m_[vals_.back()] = index; //array tail to the index
        m_.erase(val);
        
        std::swap(vals_[index], vals_.back());
        vals_.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        //int index = rand() % vals_.size();
        int index = random() % vals_.size();
        return vals_[index];
    }
private:
    // val -> index in the array
    unordered_map<int, int> m_;
    vector<int> vals_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
