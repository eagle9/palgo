/*

shaun with prefixSum idea, O(n^2)
Runtime: 1 ms, faster than 66.13% of Java online submissions for Maximum Subarray.
Memory Usage: 39.6 MB, less than 7.04% of Java online submissions for Maximum Subarray.
*/
class Solution {
    //O(n) time
    public int maxSubArray(int[] nums) {
        
        int sum =0; //store sum from 0 to i
        int res = Integer.MIN_VALUE; //res to store maximum subarray sum
        int minSum = 0; //min sum from 0, init is 0, min prefix shum

        for (int x: nums) {
            sum += x;
            //minSum = min(minSum, sum); //bug 1, minSum should 1 step slower
            res = Math.max(res, sum - minSum);
            minSum = Math.min(minSum, sum);
        }
        return res;

    }
    
    //O(n^2) time 
    public int maxSubArray000(int[] nums) {    
        
        int n = nums.length;
        int [] prefSum = new int[n+1];   //prefSum[i] is sum from 0 to i-1, or sum of first i numbers
        for (int i =1; i <= n; ++i) prefSum[i] = prefSum[i-1]+nums[i-1];

        int res = Integer.MIN_VALUE;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                // sum 0 to j,   sum from 0 to i-1
                // sum from i to j
                int sum = prefSum[j+1] - prefSum[i];
                if (sum > res) res = sum;
            }
        }
        return res;
    }
}
