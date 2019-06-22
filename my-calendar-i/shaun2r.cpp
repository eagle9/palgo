/*
shaun 2nd round try with c++, map::lower_bound and upper_bound quite different from java TreeMap floorKey and ceilingKey
similar idea to java, but details 
runtime 116ms, faster than 91%
use lower_bound to find next, and upper_bound-- to find prev
valid pointer check is kind of tricky
*/
class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        bool overlap = false;
        //returns Iterator pointing to the first element that is not less(>=) than key. If no such element is found, a past-the-end iterator (see end()) is returned.
        auto it_lower = m_.lower_bound(start);
        // start <= it_lower, start as lower bound
        if (it_lower != m_.end()) {
            int next_start = it_lower->first, next_end = it_lower->second;
            //      next_start next_end
            // start        end
            if (next_start < end) overlap = true;
        }
        
        //upper_bound returns Iterator pointing to the first element that is greater than key. If no such element is found, past-the-end (see end()) iterator is returned.
        auto it_upper = m_.upper_bound(start);
        //think start as upper
        if (it_upper != m_.begin()) { //compare to m_.end() not working, end-- will be last element
            it_upper--;
            //prev_start <= start   < it_upper->first
            int prev_start = it_upper->first, prev_end = it_upper->second;
            //        start   end
            // prev_start  prev_end
            if (start < prev_end) overlap = true;
        }
        if (overlap) return false;
        else {
            m_[start] = end;
            return true;
        }

    }

private:
    map<int,int> m_;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
