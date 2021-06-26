//jiadai c++, Your submission beats 76.60% Submissions!
//jiadai java,Your submission beats 90.80% Submissions!
public class Solution {
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        dfs(nums, 0, result);
        return result;
    }
    private void dfs(int [] nums, int start, List<List<Integer>> result) {
        if (start == nums.length) {
            result.add(convert(nums));
        }
        /*
        [1,2,3,4]
        start = 0
        i 0 - 3
        swap(1,0), dfs(nums,1,res),swap(1,0)
        start = 1, i = 1 - 3
        swap(1,1), dfs(nums,2,res), swap(1,1)
        swap(2,1), dfs(nums,2,res), swap(2,1)
        swap
        */
        for (int i = start; i < nums.length; ++i) {
            swap(nums, i, start);
            dfs(nums, start + 1, result);
            swap(nums,i, start);
        }
    }
    private void swap(int [] nums, int i, int j) {
        if (i == j) return;
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j]= temp;
    }
    private List<Integer> convert(int [] nums) {
        List<Integer> result = new ArrayList<>(nums.length);
        for (int i: nums) {
            result.add(i);
        }
        return result;
    }
};
