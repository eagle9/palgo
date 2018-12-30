class Solution {
    //grandyang idea, shaun java code, beats 32%
    public int pivotIndex(int[] nums) {
        int sumAll = 0;
        for (int i = 0; i < nums.length; i++) sumAll += nums[i];
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            //sum from 0 to i-1
            if (sumAll - nums[i] == 2 * sum) return i;
            sum += nums[i];
        }
        return -1;
    }
}
