//shaun java code
//idea check cpp code
//runtime 2ms, faster than 99%, mem less than 76%
class Solution {
    public int maximumGap(int[] nums) {
        int n = nums.length;
        if (n <= 1) return 0;
        
        int max = Integer.MIN_VALUE, min = Integer.MAX_VALUE;
        for (int num: nums) {
            max = Math.max(max, num);
            min = Math.min(min, num);
        }
        int range = max - min;
        
        int bin_size = range / n + 1;
        int [] min_vals = new int[n]; //min value in the bin
        int [] max_vals = new int[n]; //max value in the bin
        for (int i = 0; i < n; ++i) {
            min_vals[i] = Integer.MAX_VALUE;
            max_vals[i] = Integer.MIN_VALUE;
        }
        for (int num : nums) {
            int index = (num - min) / bin_size;
            min_vals[index] = Math.min(min_vals[index], num);
            max_vals[index] = Math.max(max_vals[index], num);
        }
        
        int max_gap = 0;
        int prev_max = max_vals[0];
        //start from bin 1
        for (int i = 1; i < n; ++i) {
            //if bin's min and max available
            if (min_vals[i] != Integer.MAX_VALUE) {
                max_gap = Math.max(max_gap, min_vals[i] - prev_max);
                prev_max = max_vals[i];
            }
        }
        return max_gap;
    }
}
