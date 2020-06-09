/*

naive idea, but not easy to stay away from bugs

Runtime: 498 ms, faster than 14.41% of Java online submissions for Contains Duplicate III.
Memory Usage: 39.5 MB, less than 6.82% of Java online submissions for Contains Duplicate III.


*/
class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        //for each start
        //O(n*k)
        for (int i = 0; i < nums.length; i++ ) {
            for (int j = i+1; j <=i+k && j < nums.length; j++) { //bug1 j=1
                if (Math.abs((long)nums[i] - (long)nums[j]) <= t) return true; //bug2 cast to long
            }
        }
        return false;
    }
}
