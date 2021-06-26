//shaun's first try, wrong answer
//changed return true condition, still wrong answer
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ++m_[number];
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    //shuan's second try, still wrong answer
    //the thing is that you can not return false inside the for loop
    // updated with this considered, accepted, runtime 128ms, faster than 91%
    bool find(int value) {
        for (auto it = m_.begin(); it != m_.end(); ++it) {
            int c = value - it->first;
            if (c == it->first) {
                //return m_.count(c) >= 2; //can not return false here
                if (it->second >= 2) return true;  
            }else {
                //return m_.count(c) >= 1;
                if (m_.count(c) > 0) return true;
            }
            
        }
        //return false at last
        return false;
    }
    //shaun checked with grandyang, accepted, runtime 144ms, faster than 75%
    bool find2(int value) {
        for (auto p: m_) {
            int c = value - p.first;
            if ((c == p.first && p.second >= 2) || ( c!= p.first && m_.count(c))) {
                return true;
            }
              
        }
        return false;
    }
    
private:
    unordered_map<int,int> m_;
    
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
