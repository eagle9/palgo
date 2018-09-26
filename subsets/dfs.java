public class Solution {
    /**
     * @param nums: A set of numbers
     * @return: A list of lists
     */
    public List<List<Integer>> subsets(int[] nums) {
        int n = nums.length;
        List<List<Integer>> res = new ArrayList<>();
        //if (n < 1) return res;  why this is not needed? 
        Arrays.sort(nums);
        dfs(nums, 0, new ArrayList<>(), res);
        return res;
    }
    
    /*
    @param nums: given array of distinct integers
    @param index:  to look at number at index, to add to subset or not
    @param subset: candidate subset
    @param res: results, list of subets
    */
    private void dfs(int [] nums, int index, List<Integer> subset, List<List<Integer>> res) {
        //recursion exit: 
        if (index == nums.length) {
            res.add(new ArrayList<Integer>(subset)); //key is to clone subset since it is changing
            return;
            
        }
        
        //for example given nums = [1, 2, 3], use 1 first,  you get 1, 12, 123, not use it you get 2, 23, 3, etc. so try to use it first, since we look at smaller number first
        // use nums[index] first, why?
        subset.add(nums[index]);
        dfs(nums, index+1, subset, res);
        
        //then try not use nums[index]
        subset.remove(subset.size()-1);
        dfs(nums, index+1, subset, res);
        
    }
}
