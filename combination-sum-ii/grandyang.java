/*
grandyang recursion idea, beats 31%
这道题跟之前那道 Combination Sum 组合之和 本质没有区别，只需要改动一点点即可，之前那道题给定数组中的数字可以重复使用，而这道题不能重复使用，只需要在之前的基础上修改两个地方即可，首先在递归的for循环里加上if (i > start && num[i] == num[i - 1]) continue; 这样可以防止res中出现重复项，然后就在递归调用combinationSum2DFS里面的参数换成i+1，这样就不会重复使用数组中的数字了
*/
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        if (candidates == null || candidates.length == 0) return res;
        //sorting key to prevent duplicated combinations
        Arrays.sort(candidates);
        List<Integer> cd = new ArrayList<>();
        dfs(candidates, target, 0, cd, res);
        return res;
    }
    
    private void dfs(int [] candidates, int target, int start, List<Integer> cd, List<List<Integer>> res) {
        
        if (target < 0) return;
        if (target == 0) {
            res.add(new ArrayList<Integer>(cd));
            return;
        }
        
        for (int i = start; i < candidates.length; i++) {
            //key point 2: prevent duplicated combination
            if (i > start && candidates[i] == candidates[i-1]) continue;
            cd.add(candidates[i]);
            dfs(candidates, target - candidates[i], i+1,cd,res);
            cd.remove(cd.size()-1);
        }
    }
}
