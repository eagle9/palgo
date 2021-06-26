//jz c++ --> java, Your submission beats 50.80% Submissions!
public class Solution {
    /**@param numbers : Give an array numbers of n integer
     * @return : Find all unique triplets in the array which gives the sum of zero. */
    public List<List<Integer>> threeSum(int [] nums) {
        List<List<Integer>> result = new ArrayList<>();

        Arrays.sort(nums);
        for (int i = 0; i < nums.length; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // two sum;
            int start = i + 1, end = nums.length - 1;
            int target = -nums[i];
            while (start < end) {
                if (start > i + 1 && nums[start - 1] == nums[start]) {
                    start++;
                    continue;
                }
                if (nums[start] + nums[end] < target) {
                    start++;
                } else if (nums[start] + nums[end] > target) {
                    end--;
                } else {
                    List<Integer> triple = new ArrayList<>(3);
                    triple.add(nums[i]);
                    triple.add(nums[start]);
                    triple.add(nums[end]);
                    result.add(triple);
                    start++;
                }
            }
        }
        return result;
    }
};
