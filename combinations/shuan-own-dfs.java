class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> ans = new LinkedList<>();
        List<Integer> cur = new LinkedList<>();
        helper(n, k, 1, cur, ans);
        return ans;
        
    }
    
    private void helper(int n, int k,int start, List<Integer> cur, List<List<Integer>> ans) {
        if (start > n)  {
            if (cur.size() == k) {
                ans.add(new ArrayList<>(cur));
            }
            return;
        }
        
        //take the number at start
        cur.add(start);
        helper(n, k, start+1, cur, ans);
        cur.remove(cur.size()-1);
        //not take the number at start
        helper(n, k , start+1, cur, ans);
    }
}
