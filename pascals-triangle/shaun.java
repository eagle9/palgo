import javafx.util.Pair;
//shaun own first try,  runtime 5ms, faster than 5%
//after a number of fixes, for j = 1; j <= i; j++   not j <
class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        for (int i  = 1; i <= numRows; i++) {
            List<Integer> row = new ArrayList<>();
            for (int j  = 1; j <= i; j++) {
                row.add(helper(i,j,memo));
            }
            res.add(row);
        }
        return res;
    }
    private Map<Pair,Integer> memo = new HashMap<>();
    
    private int helper(int i, int j, Map<Pair,Integer> memo) {
        Pair p = new Pair(i,j);
        if (memo.containsKey(p)) return memo.get(p);
        
        if (i == 1) return 1;
        if (j == 1 || j == i) return 1;
        
        int res = helper(i-1, j-1, memo) + helper(i-1,j, memo);
        memo.put(p, res);
        return res;
        
    }
}
