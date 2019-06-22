class MyCalendar {
    //start -> end
    TreeMap<Integer, Integer> calendar;

    MyCalendar() {
        calendar = new TreeMap();
    }
    
    //grandyang idea, shaun java code, beats 66%
    public boolean book(int start, int end) {
        //int next won't compile
        Integer next = calendar.ceilingKey(start);
        //    start ---- end, end must < next , otherwise false
        //         next ---- end'
        if (next != null && next < end) return false;  //overlap case 1
        
        Integer prev = calendar.floorKey(start);
        //     start --- end
        // prev --- end'
        if (prev != null) {
            int end_prev = calendar.get(prev);
            if (start < end_prev) return false; //overlap case 2
        }
        
        calendar.put(start,end);
        return true;    
    }
    
    //jz idea, it is harder to find okay to insert case though
    //beats 65%
    public boolean book_jz(int start, int end) {
        Integer previous = calendar.floorKey(start), next = calendar.ceilingKey(start);
        //not easy to come up with the following conditions
        //previous == null, no event earlier
        if ((previous == null || calendar.get(previous) <= start) && (next == null || end <= next)) {
            calendar.put(start, end);
            return true;
        }
        return false;
    }
}


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
