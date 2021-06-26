/*
check on the fly
Runtime: 21 ms, faster than 35.46% of Java online submissions for Subarray Sum Equals K.
Memory Usage: 52.4 MB, less than 5.43% of Java online submissions for Subarray Sum Equals K.

*/
class Solution {
    public int subarraySum(int[] nums, int k) {
        if (nums.length == 0) return 0;
        Map<Integer, Integer> mSum= new HashMap<>(); //hashtable: prefixsum to its count
        mSum.put(0,1);
        int prefixSum = 0;
        int res = 0;
        for (int i = 0; i < nums.length; ++i) {
            prefixSum += nums[i];
            
        

            if (mSum.containsKey(prefixSum -k )) {
                res += mSum.get(prefixSum - k);
            }
            
            int temp = mSum.getOrDefault(prefixSum,0);
            mSum.put(prefixSum, temp+1);
            
        }
        return res;
    }
}
