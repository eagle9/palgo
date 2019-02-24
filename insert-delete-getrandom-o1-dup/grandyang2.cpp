/*

Runtime: 72 ms, faster than 77.14% of C++ online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.
Memory Usage: 24.6 MB, less than 100.00% of C++ online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.
grandyang idea 2 use unordered_set
*/

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        m[val].insert(nums.size());
        nums.push_back(val);
        return m[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (m[val].empty()) return false;
        int idx = *m[val].begin();
        m[val].erase(idx);
        if (nums.size() - 1 != idx) {
            int t = nums.back();
            nums[idx] = t;
            m[t].erase(nums.size() - 1);
            m[t].insert(idx);
        } 
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
