class Solution {

    /**
Runtime: 5 ms, faster than 100.00% of Java online submissions for Continuous Subarray Sum.
Memory Usage: 40.8 MB, less than 56.96% of Java online submissions for Continuous Subarray Sum.
edward
     time : O(n)
     space : O(n)
     * @param nums
     * @param k
     * @return
     */
    public boolean checkSubarraySum(int[] nums, int k) {
        int sum = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            if (k != 0) {
                sum = sum % k;
            }
            if (map.containsKey(sum)) {
                if (i - map.get(sum) > 1) {
                    return true;
                }
            } else {
                map.put(sum, i);
            }
        }
        return false;
    }
}
