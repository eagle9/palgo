//lt official brute force
//TLE
class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push('(');
            } else {  // si == ')'
                
                //if (!stack.empty() && stack.peek() == '(') //found matching left in stack
                if (!stack.isEmpty())
                    stack.pop(); //pop from stack, continue
                else { //no matching left paren
                    return false;
                }
            }
        }
        return stack.empty();
    }
    public int longestValidParentheses(String s) {
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 2; j <= s.length(); j+=2) {
                // substring char from i to i+1, substring(i,i+2)
                //valid string length must be even
                if (isValid(s.substring(i, j))) {
                    maxlen = Math.max(maxlen, j - i);
                }
            }
        }
        return maxlen;
    }
}

