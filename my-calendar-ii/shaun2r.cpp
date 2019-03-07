
/*
shaun borrow hua's idea
Runtime: 140 ms, faster than 67.90% of C++ online submissions for My Calendar II.
*/

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    bool book(int start, int end) {
        for (const auto& kv: b2_) {
            const int s = kv.first, e = kv.second;
            //  s     e          s    e
            //   start end   start  end
            if (max(s,start) < min(e, end)) return false;  //triple booking
        }
        //no triple booking now
        //find overlap and update b2_
        for (const auto& kv: booked_) {
            const int s = max(start,kv.first), e = min(end, kv.second);
            if (s < e) { //double booking found
                //b2_[s] = e;
                //b2_.emplace_back(s,e);
                b2_.push_back(make_pair(s,e));
            }
        }
        //booked_[start] = end;
        //booked_.emplace_back(start,end);
        booked_.push_back(make_pair(start,end));
        return true;
    }
private: 
    vector<pair<int,int>> booked_;
    vector<pair<int,int>> b2_;
    //map<int,int> booked_; //map does not work because of the double booking
    //map<int,int> b2_;
};

/*
use a treemap<int,int> to store ts to count, ++ for start, -- for end
nice storage that allows repeated timestamps, huahua and grandyang idea
kind of slow somehow
Runtime: 244 ms, faster than 21.02% of C++ online submissions for My Calendar II.
*/
class MyCalendarTwo3 {
public:
    MyCalendarTwo3() {
        
    }
    
    bool book(int start, int end) {
        freq[start]++;
        freq[end]--;
        
        int count = 0;
        for (const auto& kv: freq){
            int k = kv.first;
            count += kv.second;
            if (count == 3) {
                freq[start]--;
                freq[end]++;
                return false;
            }
        }
        return true;
    }
    
private:
    map<int,int> freq; //timestamp to count, start ++, end --
};


/*
shaun's own idea extending from my calendar i
wrong answer, because of the double booking allowed, you can not use map to store events anymore

*/
class MyCalendarTwo0 {
public:
    MyCalendarTwo0() {
        
    }
    //shaun's first try, wrong answer
    bool book0(int start, int end) {
        bool triple = false;
        auto it_lower = b2_.lower_bound(start);
        if (it_lower != b2_.end()) {
            int next_start = it_lower->first, next_end = it_lower->second;
            //  start  end
            //     next_start  next_end
            if (next_start < end) triple = true;
        }
        auto it = b2_.upper_bound(start);
        if (it != b2_.begin()) {
            it--;
            int prev_start = it->first, prev_end = it->second;
            // prev_start   prev_end
            //      start             end
            if (start < prev_end) triple = true;
        }
        if (triple) return false;

        //no triple booking
        booked_[start] = end;
        //now update b2_
        bool overlap = false;
        it = booked_.lower_bound(start);
        if (it != booked_.end()) {
                int next_start = it->first, next_end = it->second;
                //  start     end
                //     next_start   next_end
                if (next_start < end) { //overlap results in double booking
                    b2_[next_start] = min(end,next_end);
                }
        }
        it = booked_.upper_bound(start);
        if (it != booked_.begin()) {
                it--;
                int prev_start = it->first, prev_end = it->second;
                //  prev_start   prev_end
                //         start         end
                if (start < prev_end) { //overalp results in double booking
                    b2_[start] = min(end, prev_end);
                }
        }

        return true;
    }

    
private: 
    map<int,int> booked_;
    map<int,int> b2_;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */
