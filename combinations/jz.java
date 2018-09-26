//shaun, with jz, beats 97.00%
public class Solution {
    /**
     * @param n: Given the range of numbers
     * @param k: Given the numbers of combinations
     * @return: All the combinations of k numbers out of 1..n
     */
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        
        List<Integer> cd = new ArrayList<>();
        
        //helper(n, k, 0, cd, res);
        helper(n, k, 1, cd, res);
        
        return res;
    }
    
    private void helper(int n, int k, int start, List<Integer> cd, List<List<Integer>> res) {
        if (cd.size() == k) {
            res.add(new ArrayList<>(cd));
            return;
        }
        for (int i = start; i <= n; i++) {
            cd.add(i);
            helper(n, k, i+1, cd, res);
            cd.remove(cd.size()-1);
        }
    }
}
