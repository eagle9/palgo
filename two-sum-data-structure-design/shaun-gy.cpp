//shaun c++ code with grandyang's multiset idea, multiset is bst
//cutting: use a bst (multipset) to store the numbers, find a number is logn time operation
// details: when a and value-a equal, count>=2
//runtime 132ms, faster than 64%, mem less than 19%
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        set_.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (int i: set_) {
            int other = value - i;
            if (other == i) {
                if (set_.count(i) >= 2) return true;
            } else {
                if (set_.count(other) >= 1) return true;
            }
        }
        //could not find pair that sum up to value
        return false;
    }
private:
    unordered_multiset<int> set_;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
