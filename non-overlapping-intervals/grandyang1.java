/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
//grandyang idea, sorting, runtime 39ms, faster than 46% using lambda
//runtime 3ms, faster than 92% with comparator
//understood Feb 3 2019
class Solution {
    public int eraseOverlapIntervals(Interval[] intervals) {
        int res = 0, n = intervals.length, last = 0;
        //Arrays.sort(intervals, (a,b)->Integer.compare(a.start,b.start));
        
        Arrays.sort(intervals, new Comparator<Interval>() { 
            public int compare(Interval a, Interval b){
                return Integer.compare(a.start, b.start);
            }});
            
        for (int i = 1; i < n; i++) {
            //            i.start >  i.end
            //  last.start .           last.end
            //i overlaps with last
            if (intervals[i].start < intervals[last].end) {
                res++;
                //interval i and last overlap
                //the problem asks to remove minimum number of intervals, so last will take
                //intervals i and last with earlier end, more space for remaining intervals
                //understood
                if (intervals[i].end < intervals[last].end) last = i;
            }
            else { //no overlap
                last = i;
            }
        }
        return res;
    }
}

