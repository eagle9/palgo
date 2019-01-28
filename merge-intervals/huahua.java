/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */

//huahua idea, shaun code, cleaner code that creek
//runtime 12ms, faster than 88%, 1/25/2019
class Solution {
    
    public List<Interval> merge(List<Interval> intervals) {
        if (intervals == null || intervals.size() <= 1)
			return intervals;
 
		// sort intervals by using self-defined Comparator
		Collections.sort(intervals, new Comparator<Interval>(){
		    public int compare(Interval i1, Interval i2) {
		        return i1.start - i2.start;
	        }
		});
 
		List<Interval> result = new ArrayList<Interval>();
 
		
        //iterate intervarls whose start already sorted
		for (int i = 0; i < intervals.size(); i++) {
            Interval ii = intervals.get(i);
            //ii no overlap last of result
            //fix --- == should merge, so condition 2 should be end < ii.start
            if (result.size() == 0 || result.get(result.size()-1).end < ii.start) {
                result.add(ii);
            }
            else { //overlap, need to merge
                Interval ilast = result.get(result.size()-1);
                //ilast.start --- ilast.end 
                //          ii.start < ...   ii.end
                //to merge ii with ilast, no need to insert
                ilast.start = Math.min(ilast.start,ii.start);
                ilast.end = Math.max(ilast.end, ii.end);
            }
            
		}
 
		return result;
	}
}


class Solution1 {
    //creek
    public List<Interval> merge(List<Interval> intervals) {
        if (intervals == null || intervals.size() <= 1)
			return intervals;
 
		// sort intervals by using self-defined Comparator
		Collections.sort(intervals, new Comparator<Interval>(){
		    public int compare(Interval i1, Interval i2) {
		        return i1.start - i2.start;
	        }
		});
 
		ArrayList<Interval> result = new ArrayList<Interval>();
 
		Interval prev = intervals.get(0);
        //iterate intervarls whose start already sorted
		for (int i = 1; i < intervals.size(); i++) {
			Interval curr = intervals.get(i);
            
            //   ---- prev.end 
            // curr.start--
            //overlap
			if (prev.end >= curr.start) {
				// merged case
				Interval merged = new Interval(prev.start, Math.max(prev.end, curr.end));
				prev = merged;
			} else { //no overlap, insert directly
				result.add(prev);
				prev = curr;
			}
		}
 
		result.add(prev);
 
		return result;
	}
}

