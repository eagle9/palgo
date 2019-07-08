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
    //grandyang idea, shaun java code, beats 45%
    public boolean canAttendMeetings(Interval[] intervals) {
        Arrays.sort(intervals, new Comparator<Interval>() {
            public int compare(Interval a, Interval b) {
                return a.start - b.start;
            }
        });
        
        for (int i = 1; i <= intervals.length-1; i++) {
            Interval a = intervals[i-1], b = intervals[i];
            
            //check overlap
            //   a.start -- a.end
            //       b.start      --- b.end
            //if (a.start < b.start && b.start < a.end)
            //sorted, a.start <= b.start
            if ( b.start < a.end)  //key point: a.start < b.start won't work, the most important part, double check 
                return false;
            //    a.start --- a.end
            // b.start ---b.end
            //sorted, this case won't happen
            //if (b.start < a.start && a.start < b.end)
            //    return false;
        }
        //no overlap found...
        return true;
    }
}
