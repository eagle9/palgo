/*
Runtime: 3 ms, faster than 76.41% of Java online submissions for Longest Continuous Increasing Subsequence.
Memory Usage: 29.9 MB, less than 0.96% of Java online submissions for Longest Continuous Increasing Subsequence.
shaun own code and idea, Feb 9 2019
*/
class Solution {
    public int findLengthOfLCIS(int[] nums) {
        int start = 0, n = nums.length;
        int res = 0;
        for (int i = 0; i < n; i++) {
            int len = i - start + 1;
            if (i == 0) {
                //no need to compare to prev
                
                if (len > res) {
                    res= len;
                    
                }
                continue;
            }
            //now i >= 1
            if (nums[i] > nums[i-1]) {
                if (len > res) {
                    res= len;
                    
                }
            }else {
                start = i;
            }
            
        }
        return res;
    }
}
