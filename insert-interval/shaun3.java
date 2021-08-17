class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        int n = intervals.length;

        List<int[]> res = new LinkedList<>();
        int pos = 0; //position of new interval to insert, how many before it?
        //newInterval will be updated. 
        
        //for (int i = 0; i < n; i++) {
            //Interval ii = intervals.get(i);
            
        for (int [] ii: intervals) {
            // new interval is after current interval ii
            if (ii[1] < newInterval[0]) {
                res.add(ii);
                pos++;
            // new interval is before current interval ii
            }else if (newInterval[1] < ii[0]) {
                res.add(ii);
            //overlapping, update the newInterval
            }else {
                newInterval[0] = Math.min(newInterval[0], ii[0]);
                newInterval[1] = Math.max(newInterval[1], ii[1]);
            }
        }
        res.add(pos, newInterval);
        int [][] res2 = new int[res.size()][2];
        res.toArray(res2);
        return res2;
    }
}
    
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

