class MyCalendarTwo {

    public MyCalendarTwo() {
        
    }
    //grandyang v1 idea, use list2 to store double bookings, list1 to store legal bookings
    //shaun java code using int[] as pair, beats 61%
    
    public boolean book(int start, int end) {
        
        //list2 stores ranges that already double booked
        for (int [] p: list2) {
            //                    p[0] ---- p[1]
            // okay1                                  start --- end
            // okay2 start -- end  
            //start--end no overlap with p
            if (start >= p[1] || end <= p[0]) continue;
            
            //otherwise, triple booked since set2 stores double bookings
            //start--end leads to triple booking, return false, done
            else return false;
        }
        
        //list1 store complete ranges
        for (int [] p: list1) {
            //                p.start --- p.end
            //                                     start---end
            //    start--end
            //no overlap
            if (start >= p[1] || end <= p[0]) continue;
            
            //found overlap, store double booking (overlapping range)into set2
            // start takes max, end takes min
            else list2.add(new int []{Math.max(start, p[0]), Math.min(end, p[1])});
        }
        
        //no triple booking so far
        list1.add(new int []{start,end});
        return true;
    }
    
    private List<int[]> list1 = new ArrayList<>();
    private List<int[]> list2 = new ArrayList<>();
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
