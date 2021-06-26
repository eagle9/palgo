/*

Runtime: 15 ms, faster than 7.30% of Java online submissions for Merge Intervals.
Memory Usage: 44.2 MB, less than 36.23% of Java online submissions for Merge Intervals.
*/
class Solution {
    public int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length == 0) return intervals;
        Arrays.sort(intervals, (a,b) -> a[0] - b[0]);
        List<int[]> res = new ArrayList<>();
        res.add(intervals[0]);
        int [] prev = intervals[0];
        
        for (int i = 1; i < intervals.length; i++) {
        	int [] cur = intervals[i];
        	//prev.start   prev.end
        	//                       cur.start  cur
        	if (prev[1] < cur[0]) { //no overlap
        		res.add(cur);
        		prev = cur;
        	}
        	//prev.start  prev.end 
        	//          cur.start   cur.end
        	//  cur.start <= prev.end
        	else { //merge
        		prev[1] = Math.max(prev[1], cur[1]);
        	}
        }
        int [] [] ans = new int[res.size()][2];
        for (int i = 0; i < res.size(); i++) {
            ans[i] = res.get(i);
        }
        return ans;
    }
}


