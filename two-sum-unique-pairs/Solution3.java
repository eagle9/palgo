public class Solution {
    /*
     * @param nums: an array of integer
     * @param target: An integer
     * @return: An integer
     */
     //jz, Your submission beats 73.60% Submissions!
     //use HashMap
    public int twoSum6(int[] nums, int target) {
        if (nums == null || nums.length < 2) {
            return 0;
        }
        
        Map<Integer, Boolean> map = new HashMap<>();
        
        int count = 0;
        for (int num : nums) {
            if (map.containsKey(target - num)) {
                if (!map.get(target - num)) {
                    count++;
                    map.put(target - num, true);
                    map.put(num, true);
                }
            } else {
                map.put(num, false);
            }
        }
        return count;
    }
}
