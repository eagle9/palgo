class MyCalendarTwo {

    public MyCalendarTwo() {
        
    }
    //grandyang v1 idea, use set2 to store double bookings, set1 to store legal bookings
    //shaun java code, beats 61%
    
    public boolean book(int start, int end) {
        
        //set2 stores ranges that already double booked
        for (Pair p: set2) {
            //                    p.start ---- p.end
            // okay1                                  start --- end
            // okay2 start -- end  
            //start--end no overlap with p
            if (start >= p.end || end <= p.start) continue;
            
            //otherwise, triple booked since set2 stores double bookings
            //start--end leads to triple booking, return false, done
            else return false;
        }
        
        //set1 store complete ranges
        for (Pair p: set1) {
            //                p.start --- p.end
            //                                     start---end
            //    start--end
            //no overlap
            if (start >= p.end || end <= p.start) continue;
            
            //found overlap, store double booking (overlapping range)into set2
            // start takes max, end takes min
            else set2.add(new Pair(Math.max(start, p.start), Math.min(end, p.end)));
        }
        
        //no triple booking so far
        set1.add(new Pair(start,end));
        return true;
    }
    private class Pair{
        int start;
        int end;
        public Pair(int start, int end) {
            this.start = start;
            this.end =end;
        }
    }
    private Set<Pair> set1 = new HashSet<>();
    private Set<Pair> set2 = new HashSet<>();
}

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * boolean param_1 = obj.book(start,end);
 */


//grandyang c++ v1, beats 67%
/*
class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    
    bool book(int start, int end) {
        for (auto a : s2) {
            if (start >= a.second || end <= a.first) continue;
            else return false;
        }
        for (auto a : s1) {
            if (start >= a.second || end <= a.first) continue;
            else s2.insert({max(start, a.first), min(end, a.second)});
        }
        s1.insert({start, end});
        return true;
    }

private:
    set<pair<int, int>> s1, s2;
};
*/
