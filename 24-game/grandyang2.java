//grandyang idea2, dfs,  c++, runtime 20ms, faster than 50%
//shaun java, dfs, 12ms, faster than 84%
class Solution {
    public  final double eps = 0.001;
    private boolean res = false;
    private char [] ops = {'+', '-', '*', '/'};
    
    public boolean judgePoint24(int[] nums) {
        
        Arrays.sort(nums);
        List<Double> a = new ArrayList<>();
        for (int i: nums) a.add((double)i);
        return helper(a);
        
    }
    private boolean helper(List<Double> nums) {
        
        if (nums.size() == 1) return Math.abs(nums.get(0) - 24) < eps;
        
        //take any two numbers
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i == j) continue;
                List<Double> t = new ArrayList<>();
                for (int k = 0; k < nums.size(); ++k) {
                    if (k != i && k != j) t.add(nums.get(k));
                }
                for (char op : ops) {
                    if ((op == '+' || op == '*') && i > j) continue;
                    if (op == '/' && nums.get(j) < eps) continue;
                    switch(op) {
                        case '+': t.add(nums.get(i) + nums.get(j)); break;
                        case '-': t.add(nums.get(i) - nums.get(j)); break;
                        case '*': t.add(nums.get(i) * nums.get(j)); break;
                        case '/': t.add(nums.get(i) / nums.get(j)); break;
                    }
                    if (helper(t)) return true;
                    t.remove(t.size()-1);
                }
            }
        }
        return false;
    }
}
