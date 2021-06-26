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

//jz version 1, beats 79.40%
//shaun's useing merge2i and inline Comparator, beats 93.00%
class Solution {
    /**
     * @param intervals: Sorted interval list.
     * @return: A new sorted interval list.
     */
     //jz version1
    public List<Interval> merge000(List<Interval> intervals) {
        if (intervals == null || intervals.isEmpty()) return intervals;

        List<Interval> result = new ArrayList<Interval>();
        // sort with Comparator
        //Collections.sort(intervals, new IntervalComparator());
		//key points: new Comparator<T>, int compare method made public
        Collections.sort(intervals, new Comparator<Interval>() {
            public int compare(Interval a, Interval b) {
                return a.start - b.start;
            }
        });
        Interval prev = intervals.get(0);
        for (Interval interval : intervals) {
			//no overlapping
            if (interval.start > prev.end) {
                result.add(prev);
                prev = interval;
            } else { //overlapping
                prev.start = Math.min(prev.start, interval.start);
                prev.end = Math.max(prev.end, interval.end);
            }
        }
        result.add(prev);

        return result;
    }
    
    /**
     * @param intervals: Sorted interval list.
     * @return: A new sorted interval list.
     */
     //shaun's using merge2i
    public List<Interval> merge(List<Interval> intervals) {
        if (intervals == null || intervals.isEmpty()) return intervals;

        List<Interval> results = new ArrayList<Interval>();
        // sort with Comparator, by start
        Collections.sort(intervals, new IntervalComparator());
        Interval last = null;
        for (Interval curr : intervals) {
            last = merge2i(results, last, curr);
        }
        if (last != null)
            results.add(last);

        return results;
    }
    
    private Interval merge2i(List<Interval> results, Interval last, Interval curr) {
        if (last == null) return curr;
        if (last.end < curr.start) {
            results.add(last);
            return curr;
            
        }
        //last.end >= currt.start
        last.end = Math.max(last.end, curr.end);
        return last;
    }
    private class IntervalComparator implements Comparator<Interval> {
        public int compare(Interval a, Interval b) {
            return a.start - b.start;
        }
    }

}
