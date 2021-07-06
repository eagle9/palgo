//gy idea, shaun understood
//accu sum mod k and save to hash
class Solution {
    /**

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
            if (map.containsKey(sum)) { // remainder sum already in map
                //j = map.get(sum)
                //i and j same remainder
                //from j to i sum must k's multiple
                if (i - map.get(sum) > 1) {
                    return true;
                }
            } else {
                map.put(sum, i);
            }
        }
        //could not find it
        return false;
    }
}
