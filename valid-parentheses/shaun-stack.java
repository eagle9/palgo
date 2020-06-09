//Runtime: 1 ms, faster than 98.67% of Java online submissions for Valid Parentheses.
class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for (char c: s.toCharArray()) {
            if (c == '{' || c == '[' || c == '(' ) {
                st.push(c);
            }else {
                if (st.isEmpty()) return false;
                char t = st.pop();
                if (t == '[' && c != ']' ||
                    t == '{' && c != '}' ||
                    t == '(' && c != ')') return false;
            }
        }
        return st.isEmpty();
    }
}
