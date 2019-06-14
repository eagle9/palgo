//shaun round2,  accepted after two fixes, you have to use both floorKey and ceilingKey to find prev and last events
//summarize overlap cases from both cases
//runtime 84ms, faster than 96%
class MyCalendar {

	private TreeMap<Integer,Integer> tmap = null;
    public MyCalendar() {
        tmap = new TreeMap<>();
    }
    
    //return true if the event can be added to the calendar successfully without causing a double booking. 
    //Otherwise, return false and do not add the event to the calendar.
    public boolean book(int start, int end) {
        if (tmap.size() ==0)  {
        	tmap.put(start, end);
        	return true;
        }
        
        //tmap not empty, prev < start, but being max
        Integer prevStart = tmap.floorKey(start);
        //start < lastStart, being min
        Integer lastStart = tmap.ceilingKey(start);
        //prevStart        lastStart
        //         start end
        boolean overlap = false;
        if (prevStart != null) {
        
        	Integer prevEnd = tmap.get(prevStart);
        	//prevStart prevEnd
        	//                   start     end
        	if ( start < prevEnd) { //no overlap
        		overlap = true;
        	}
        }
        if (lastStart != null) {
        	Integer lastEnd = tmap.get(lastStart);
        	//  start    end
        	//           lastStart  lastEnd
        	if (lastStart < end) { //no overlap
        		overlap = true;
        	}
        }
        if (overlap) return false;
        
        tmap.put(start, end);
        return true;
    
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
