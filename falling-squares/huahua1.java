// Author: Huahua, brute forece, runtime 43ms, faster than 44%
//easy to understand and remember
class Solution {

    public List<Integer> fallingSquares(int[][] positions) {
        List<Integer> ans = new ArrayList<>();
        List<Interval> intervals = new ArrayList<>();
        int maxHeight = Integer.MIN_VALUE;
        for (int [] p: positions) {
            int start = p[0];
            int end = start + p[1];            
            int baseHeight = 0;
            //i.start i.end   
            // start end
            for (Interval i : intervals) {
                //two interval no overlap
                if (i.start >= end || i.end <= start)             
                    continue;
                //find interveral i has overlap with p(left, len)
                baseHeight = Math.max(baseHeight, i.height);
            }
            int height = p[1] + baseHeight;
            intervals.add( new Interval(start, end, height));
            maxHeight = Math.max(maxHeight, height);
            ans.add(maxHeight);
        }
        return ans;
    }
    class Interval {
        int start;
        int end;
        int height;
        public Interval(int start, int end, int height) {
            this.start = start;
            this.end = end;
            this.height = height;
        }
            
    };
};
