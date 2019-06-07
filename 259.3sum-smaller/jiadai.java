//jiadai c++ Your submission beats 100.00% Submissions!
//-->java
public class Solution {
    /**
     * @param nums:  an array of n integers
     * @param target: a target
     * @return: the number of index triplets satisfy the condition nums[i] + nums[j] + nums[k] < target
     */
    public int threeSumSmaller(int [] nums, int target) {
        int n = nums.length;
        if (n < 2) return 0;
        Arrays.sort(nums);
        int count = 0;
        for (int i = 0; i < n - 2; ++i) {
            int start = i + 1, end = n - 1;
            while (start < end) {
                if (nums[i] + nums[start] + nums[end] >= target) {
                    --end;
                }
                else { //3sum < target
                    count += end - start; //why not count++, draw on paper, found not just 1, but end-start 
                    ++start;
                }
            }
        }
        return count;
    }
};
