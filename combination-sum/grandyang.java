/*
grandyang recursion idea, beats 41%
像这种结果要求返回所有符合要求解的题十有八九都是要利用到递归，而且解题的思路都大同小异，相类似的题目有 Path Sum II，Subsets II，Permutations，Permutations II，Combinations 等等，如果仔细研究这些题目发现都是一个套路，都是需要另写一个递归函数，这里我们新加入三个变量，start记录当前的递归到的下标，out为一个解，res保存所有已经得到的解，每次调用新的递归函数时，此时的target要减去当前数组的的数


*/
class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> cd = new ArrayList<>();
        dfs(candidates, target, 0, cd, res);
        return res;
    }
    //key point: understand start, used to reduce duplicate combinations
    private void dfs(int [] candidates, int target, int start, List<Integer> cd, List<List<Integer>> res) {
        
        if (target < 0) return;
        else if (target == 0) {
            res.add(new ArrayList<>(cd));
            return;
        }
        for (int i = start; i < candidates.length; ++i) {
            cd.add(candidates[i]);
            //next recursion start with i, you can use a number repeatedly
            //but you can not use numbers before it, this is key to reduce duplicated combination
            //for example 223, but not 322
            dfs(candidates, target - candidates[i], i, cd, res);
            cd.remove(cd.size()-1);
        }
    }
}
