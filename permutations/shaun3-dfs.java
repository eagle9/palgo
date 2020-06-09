/*
Runtime: 1 ms, faster than 90.25% of Java online submissions for Permutations.
Memory Usage: 39.8 MB, less than 5.68% of Java online submissions for Permutations.

shaun 3rd accepted after bug fixes
how to break through, break through with what you need to solve it
*/
class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new LinkedList<>();
        List<Integer> cur = new LinkedList<>();
        boolean [] used = new boolean[nums.length];
        helper(nums, used, cur, res);
        return res;
    }
    
    // k numbers considered so far
    private void helper(int[] nums, boolean [] used,
                        List<Integer> cur, List<List<Integer>> res) {
        if (cur.size() == nums.length) {
            res.add(new LinkedList<>(cur));
            return;
        }
        
        for (int i = 0; i < nums.length; i++) {
            if (used[i]) continue;
            cur.add(nums[i]);
            
            used[i] = true;
            helper(nums, used, cur, res);
            cur.remove(cur.size()-1);
            used[i] = false;
        }
    }
}

/*
1, [1]    1,[2]      1,[3]

2, 


*/
