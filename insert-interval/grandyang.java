/**
 * Definition of Interval:
 * public classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this.start = start;
 *         this.end = end;
 *     }
 * }
 */
//grandyang idea, shaun code, beats 33%, same idea as jz 
//beats 56% when for (Interval ii: intervals)
public class Solution {
    /**
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {
        // write your code here
        
        List<Interval> res = new ArrayList<>();
        int n = intervals.size();
        int pos = 0; //position of new interval to insert
        //newInterval will be updated. 
        
        //for (int i = 0; i < n; i++) {
            //Interval ii = intervals.get(i);
            
        for (Interval ii: intervals) {
            // new after i
            if (ii.end < newInterval.start) {
                res.add(ii);
                pos++;
            // new before i
            }else if (newInterval.end < ii.start) {
                res.add(ii);
            //overlapping, update the newInterval
            }else {
                newInterval.start = Math.min(newInterval.start, ii.start);
                newInterval.end = Math.max(newInterval.end, ii.end);
            }
        }
        res.add(pos, newInterval);
        return res;
    }
}

