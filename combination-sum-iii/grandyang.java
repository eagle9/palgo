/*
这道题题是组合之和系列的第三道题，跟之前两道Combination Sum 组合之和，Combination Sum II 组合之和之二都不太一样，那两道的联系比较紧密，变化不大，而这道跟它们最显著的不同就是这道题的个数是固定的，为k。个人认为这道题跟那道Combinations 组合项更相似一些，但是那道题只是排序，对k个数字之和又没有要求。所以实际上这道题是它们的综合体，两者杂糅到一起就是这道题的解法了，n是k个数字之和，如果n小于0，则直接返回，如果n正好等于0，而且此时cd中数字的个数正好为k，说明此时是一个正确解，将其存入结果res中，
beats 78%
*/
class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> cd= new ArrayList<>();
        helper(k, n, 1, cd, res);
        return res;
    }
    private void helper(int k, int target, int start, List<Integer> cd, List<List<Integer>> res) {
        if (target < 0) return;
        if (target == 0 && cd.size() == k) {
            //make a deep copy of cd
            res.add(new ArrayList<Integer>(cd));
            return;
        }
        
        for (int i = start; i <= 9; ++i) {
            cd.add(i);
            helper(k, target - i, i + 1, cd, res);
            cd.remove(cd.size()-1);
        }
    }
}
