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

//jz lin huchong, time = O(n+m), beats 90.60%
//idea is to look at intervals by start in ascending order
  //first interval, next interval
      //no overlap --> first interval to results
      //overlap --> merge, update first interval's end
//now shaun understands
public class Solution {
    /**
     * @param list1: one of the given list
     * @param list2: another list
     * @return: the new sorted list of interval
     */
    public List<Interval> mergeTwoInterval(List<Interval> list1, List<Interval> list2) {
        List<Interval> results = new ArrayList<>();
        if (list1 == null || list2 == null) {
            return results;
        }
        
        //kind of two pointers, looking at two targets
        Interval last = null, curt = null; //curt is current invertal
        int i = 0, j = 0;
        int n = list1.size(), m = list2.size();
        //looking at start in ascending order
        while (i < n && j < m) {
            if (list1.get(i).start < list2.get(j).start) {
                curt = list1.get(i);
                i++;
            } else {
                curt = list2.get(j);
                j++;
            }
            
            last = merge(results, last, curt);
        }
        
        while (i < n) {
            last = merge(results, last, list1.get(i));
            i++;
        }
        
        while (j < m) {
            last = merge(results, last, list2.get(j));
            j++;
        }
        
        if (last != null) {
            results.add(last);
        }
        return results;
    }
    
    //merge 2 intervals: last and curt
    private Interval merge(List<Interval> results, Interval last, Interval curt) {
        if (last == null) {
            return curt;
        }
        
        if (last.end < curt.start) {
            // last no overlapping, add to results
            results.add(last);
            return curt;
        }
        //curt.start <= last.end, merge 
        last.end = Math.max(last.end, curt.end);
        return last;
    }
}
