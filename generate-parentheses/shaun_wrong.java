class Solution1 {
    public List<String> generateParenthesis(int n) {
        return helper(n);
    }
    //unfortunately, (())(()) can be extended from helper(n-1)  ())(()
    private List<String> helper(int n) {
        List<String> res = new ArrayList<>();
        if (n == 1) {
            res.add("()");
            return res;
        }
        //now n >= 2
        Set<String> set = new HashSet<>();
        List<String> list = helper(n-1);
        for (String s: list) {
            String next  = s + "()";
            if (!set.contains(next)) 
                set.add(next);
            next = "()" + s;
            if (!set.contains(next)) 
                set.add(next);
            next = "(" + s + ")";
            if (!set.contains(next)) 
                set.add(next);
        }
        res.addAll(set);
        return res;
    }
}
