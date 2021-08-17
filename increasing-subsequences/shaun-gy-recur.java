//shaun gy idea recur, a bit slow
class Solution {
    public List<List<Integer>> findSubsequences(int[] nums) {
        Set<List<Integer>> res = new HashSet<>();
        List<Integer> out = new LinkedList<>();
        helper(nums, 0, out, res);
        List<List<Integer>> ans = new LinkedList<>();
        ans.addAll(res);
        return ans;
    }
    void helper(int [] nums, int start, List<Integer> out, Set<List<Integer>> res) {
        if (out.size() >= 2) {
            List<Integer> temp = new LinkedList<>();
            temp.addAll(out);
            res.add(temp);
        }
        for (int i = start; i < nums.length; ++i) {
            //current candidate not empty and from last element to nums[i] dropping
            if (!out.isEmpty() && out.get(out.size()-1) > nums[i]) continue;
            //out not empty and increasing>=
            out.add(nums[i]);
            //move on to next step
            helper(nums, i + 1, out, res);
            //expored nums[i], back track
            out.remove(out.size()-1);
        }
    }
}

