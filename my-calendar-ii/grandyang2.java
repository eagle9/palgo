//grandyang idea2, runtime 1100ms, faster than 4%
//Feb 2 2019
class MyCalendarTwo {

    public MyCalendarTwo() {
        
    }
    
    public boolean book(int start, int end) {
        Integer count = freq.getOrDefault(start,0);
        freq.put(start,count+1);
        count = freq.getOrDefault(end,0);
        freq.put(end,count-1);
        int cnt = 0;
        for (Integer k: freq.keySet()) {
            cnt += freq.get(k);
            if (cnt == 3) {
                freq.put(start, freq.get(start)-1);
                freq.put(end,freq.get(end)+1);
                return false;
            }
        }
        //no triple bookings
        return true;
    }
    private Map<Integer,Integer> freq = new TreeMap<>();
}

