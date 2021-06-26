/**
 * Definition for an interval.
 * public class Interval {
 *     int start;
 *     int end;
 *     Interval() { start = 0; end = 0; }
 *     Interval(int s, int e) { start = s; end = e; }
 * }
 */
//shaun's second round, accepted upon first submission, 10ms, faster than 96%
class Solution {
    public List<Interval> merge(List<Interval> intervals) {
    	if (intervals == null || intervals.size() == 0) return intervals;
    	
        Collections.sort(intervals, new Comparator<Interval>(){
            public int compare(Interval a, Interval b) {
                return a.start - b.start;
            }
        });
        List<Interval> res = new ArrayList<>();
        int n = intervals.size();
        res.add(intervals.get(0));
        Interval prev = intervals.get(0);
        
        for (int i = 1; i < n; i++) {
        	Interval cur = intervals.get(i);
        	//prev.start   prev.end
        	//                       cur.start  cur
        	if (prev.end < cur.start) { //no overlap
        		res.add(cur);
        		prev = cur;
        	}
        	//prev.start  prev.end 
        	//          cur.start   cur.end
        	//  cur.start <= prev.end
        	else { //merge
        		prev.end = Math.max(prev.end, cur.end);
        	}
        }
        return res;
    }
}
