/*
Runtime: 5 ms, faster than 71.21% of Java online submissions for Contains Duplicate.
Memory Usage: 43.8 MB, less than 67.24% of Java online submissions for Contains Duplicate.

*/
class Solution {
    public boolean containsDuplicate1(int[] nums) {
        Set<Integer> set = new HashSet<>(nums.length);
        for (int x: nums) {
            if (set.contains(x)) return true;
            set.add(x);
        }
        return false;
    }
    
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 1; ++i) {
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
}
