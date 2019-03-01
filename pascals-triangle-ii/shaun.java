//shaun's own first try, runtime 7ms, faster than 10%
import javafx.util.Pair;
class Solution {
    private Map<Pair,Integer> memo = new HashMap<>();
    public List<Integer> getRow(int rowIndex) {
        List<Integer> res = new ArrayList<>();
        for (int j = 1; j <= rowIndex+1; j++) {
            res.add(helper(rowIndex+1,j,memo));
        }
        return res;
    }
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


