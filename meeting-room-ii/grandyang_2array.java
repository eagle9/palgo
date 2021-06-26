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
    
    //grandyang, using two arrays, beats 100%
    public int minMeetingRooms(Interval[] intervals) {
        int n = intervals.length;
        int [] starts = new int[n];
        int [] ends = new int[n];
        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i].start;
            ends[i] = intervals[i].end;
        }
        Arrays.sort(starts);
        Arrays.sort(ends);
        
        //using two different pointer for ends and starts array
        int endpos = 0;
        int count = 0;
        for (int i =0; i < n; i++) {
            //if a meeting starts before another meeting ends
            if (starts[i] < ends[endpos]) {
                count++;  //i starts before prev end
            }else {  //end[ endpos] <=  starts[i], a meeting ends, focus on next meeting ends
                endpos++;
            }
            //max = Math.max(count,max);
        }
        return count;
    }
}
