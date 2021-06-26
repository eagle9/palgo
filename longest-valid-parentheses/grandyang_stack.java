//runtime 16ms, faster than 57%
//grandyang idea using stack
class Solution {
    public int longestValidParentheses(String s) {
        int res = 0, start = 0;
        Stack<Integer> st = new Stack<>();
        char [] c = s.toCharArray();
        for (int i = 0; i < c.length; ++i) {
            if (c[i] == '(') st.push(i);
            else if (c[i] == ')') {
                if (st.isEmpty()) start = i + 1; // before i is invalid, reset start
                else {
                    st.pop();
                    //st.peek() no match, so valid from st.peek()+1 to i
                    //lenth = index diff + 1
                    res = st.isEmpty() ? Math.max(res, i - start + 1) : Math.max(res, i - st.peek());
                }
            }
        }
        return res;
        
    }
}
