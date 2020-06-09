/*
Runtime: 5 ms, faster than 53.15% of Java online submissions for 3Sum Closest.
Memory Usage: 39.1 MB, less than 6.67% of Java online submissions for 3Sum Closest.
*/


class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        int minDiff = Integer.MAX_VALUE, res = 0;
        for (int i = 0; i < n-2; ++i) {
            int left = i+1, right = n-1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    if (target - sum < minDiff) {
                        minDiff = target - sum;
                        res = sum;
                    }
                    left++;
                }else { //sum >= target
                    if (sum - target < minDiff) {
                        minDiff = sum - target;
                        res = sum;
                    }
                    right--;
                }
            }
        }
        return res;
    }
}
