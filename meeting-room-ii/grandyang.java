/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
class Solution {
    
    //beats 35%, grandyang treemap idea and shaun coded, meeting may start or end at the same time.  remember that treemap keySet returns a set of sorted keys, no duplication of keys in the set.
    public int minMeetingRooms(Interval[] intervals) {
        
        TreeMap<Integer,Integer> map = new TreeMap<>();
        for (Interval i: intervals) {
            if (!map.containsKey(i.start))
                map.put(i.start,1);
            else
                map.put(i.start, map.get(i.start)+1);
            //System.out.println(i.start + " " + map.get(i.start));
            if (!map.containsKey(i.end))
                map.put(i.end,-1);
            else
                map.put(i.end, map.get(i.end)-1);
            //System.out.println(i.end + " " + map.get(i.end));
        }
        
        int rooms = 0;
        int ans = 0;
        for (Integer t: map.keySet()) {
            rooms+= map.get(t);
            ans = Math.max(ans,rooms);
            //System.out.println(t + " " + map.get(t));
        }
        return ans;
    }
}
