public class Solution {
    /**
     * @param nums  a sorted integer array
     * @param lower an integer
     * @param upper an integer
     * @return a list of its missing ranges
     */

    //jz idea, beats 100%, great idea and fast. 
    //key point: 1) smart addRange function
    //   2) use long to store +1 and -1 result
    public List<String> findMissingRanges(int[] nums, int lower, int upper) {
        // Write your code here
        List<String> ans = new ArrayList<>();
        //when the input array is empty or null
        if (nums == null || nums.length == 0) {
            addRange(ans, lower, upper);
            return ans;
        }

        addRange(ans, lower, (long)nums[0] - 1);
        for (int i = 1; i < nums.length; i++) {
            addRange(ans, (long)nums[i - 1] + 1, (long)nums[i] - 1);
        }
        addRange(ans, (long)nums[nums.length - 1] + 1, upper);
        return ans;
    }
    
    //smart function to add range
    void addRange(List<String> ans, long st, long ed) {
        if (st > ed) {
            return;
        }
        if (st == ed) {
            ans.add(st + "");
            return;
        }
        ans.add(st + "->" + ed);
    }

}
