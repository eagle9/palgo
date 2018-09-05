//ling hucong, Your submission beats 84.40% Submissions!
public class Solution {
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> results = new ArrayList<>();
        Arrays.sort(nums);
        dfs(nums, 0, new ArrayList<Integer>(), results);
        return results;
    }
    
    // recursive
    // start with subset ，with nums start from index, all combination to results
    private void dfs(int[] nums,
                     int index,
                     List<Integer> subset,
                     List<List<Integer>> results) {
        // exit of the recursion
        if (index == nums.length) {
            results.add(new ArrayList<Integer>(subset));
            return;
        }
        
        // 2. recusive, how to enter next level
        
        // choose nums[index]
        subset.add(nums[index]);
        dfs(nums, index + 1, subset, results);
        
        // not choose nums[index]
        subset.remove(subset.size() - 1);
        dfs(nums, index + 1, subset, results);
    }
}
