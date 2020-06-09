/*
Runtime: 1 ms, faster than 54.91% of Java online submissions for Subsets.
Memory Usage: 39.5 MB, less than 5.74% of Java online submissions for Subsets.

shaun dfs backtracking idea

*/
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        
        List<List<Integer>> res = new LinkedList<>();
        //subset size n from 0 to nums.size()
        for (int n = 0; n <= nums.length; ++n) {
            List<Integer> cur = new LinkedList<>();
            helper(nums,n,0,cur,res);
        }
        return res;
    }

    //take n number combination out of nums, from start
    private void helper(int [] nums, int n, int start, 
                        List<Integer> cur, List<List<Integer>> res){
        if (cur.size() == n) {
            //key to clone cur and add to res
            res.add(new LinkedList<Integer>(cur));
            return;
        }
        //try number from start to nums.size-1
        for (int i = start; i < nums.length; ++i) {
            cur.add(nums[i]); //use nums[i]
            helper(nums,n,i+1,cur,res);
            cur.remove(cur.size()-1); //not use nums[i]
        }
    }

}
