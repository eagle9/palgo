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
/*jz linhuchong beats 84.60%
use PriorityQueue
assume each list size n，and there are k lists。
time = O(nklogk)
space = O(k)


mergeShaun to implement merge,   beats 91.40%
mergeShaun is from merge two sorted interval lists

how about merge2 (results, last, curr) on the fly?

Shaun modified both mergeKSortedIntervalLists and merge. Shaun's program works and beats 91.40%. Shaun's final version is more of natural extension of merge two sorted interval lists solution
*/
class Pair {
    int row, col;
    public Pair(int row, int col) {
        this.row = row;
        this.col = col;
    }
}

public class Solution {
    
    
    public List<Interval> mergeKSortedIntervalLists(List<List<Interval>> intervals) {
        int k = intervals.size();
        PriorityQueue<Pair> queue = new PriorityQueue<>(
          k,
          new Comparator<Pair>() {
            public int compare(Pair e1, Pair e2) {
                return intervals.get(e1.row).get(e1.col).start - 
                  intervals.get(e2.row).get(e2.col).start;
            }
          }
        );
        
        //add each list's head to PriorityQueue
        for (int i = 0; i < k; i ++) {
            if (intervals.get(i).size() > 0) {
                queue.add(new Pair(i, 0));
            }
        }
        
        List<Interval> results = new ArrayList<>();
        Interval last = null;
        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            Interval curr = intervals.get(pair.row).get(pair.col);
            last = mergeTwoIntervals(results, last, curr);
            pair.col++; //next in that row
            if (pair.col < intervals.get(pair.row).size()) {
                queue.add(pair);
            }
        }
        
        if (last != null) results.add(last);
        return results;
    }
    
    public List<Interval> mergeKSortedIntervalLists000(List<List<Interval>> intervals) {
        int k = intervals.size();
        PriorityQueue<Pair> queue = new PriorityQueue<>(
          k,
          new Comparator<Pair>() {
            public int compare(Pair e1, Pair e2) {
                return intervals.get(e1.row).get(e1.col).start - 
                  intervals.get(e2.row).get(e2.col).start;
            }
          }
        );
        
        //add each list's head to PriorityQueue
        for (int i = 0; i < k; i ++) {
            if (intervals.get(i).size() > 0) {
                queue.add(new Pair(i, 0));
            }
        }
        
        List<Interval> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            Pair pair = queue.poll();
            result.add(intervals.get(pair.row).get(pair.col));
            pair.col++;
            if (pair.col < intervals.get(pair.row).size()) {
                queue.add(pair);
            }
        }
        //result has all intervals sorted by itstart
        return mergeShaun(result);
        //return mergeLHC(result)
    }
    
    private Interval mergeTwoIntervals(List<Interval> results, Interval last, Interval curr) {
        if (last == null) return curr;
        if (last.end < curr.start) {
            results.add(last);
            return curr;
        }
        last.end = Math.max(last.end, curr.end);
        return last;
    }
    
    private List<Interval> mergeShaun(List<Interval> Intervals) {
        if (Intervals.size() <= 1) {
            return Intervals;
        }
        List<Interval> results = new ArrayList<>();
        Interval last = null;
        for (Interval curr: Intervals) {
            last = mergeTwoIntervals(results, last, curr);
        }
        if (last != null) results.add(last); //don't miss this one
        return results;
    }
    
    private List<Interval> mergeLHC(List<Interval> intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        
        List<Interval> result = new ArrayList<>();
        int start = intervals.get(0).start;
        int end = intervals.get(0).end;
        for (Interval interval : intervals) {
            if (interval.start <= end) {
                end = Math.max(end, interval.end);
            } else {
                result.add(new Interval(start, end));
                start = interval.start;
                end = interval.end;
            }
        }
        // kickoff the last interval
        result.add(new Interval(start, end));
        
        return result;
    }
}
