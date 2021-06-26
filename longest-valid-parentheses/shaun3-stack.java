/*
store char into stack, reduce char that can be matched, char that can not be matched stay in the stack
store their index, not the char itself
Runtime: 3 ms, faster than 30.46% of Java online submissions for Longest Valid Parentheses.
Memory Usage: 39.6 MB, less than 5.88% of Java online submissions for Longest Valid Parentheses.

*/
class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> st = new Stack<>();//stack to store char index in s that can not be matched
        for (int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) == '(') st.push(i);
            else { //  ==)
                if (st.isEmpty()) st.push(i); //no match
                else {
                    //() matched, pop stack, no enter i into stack
                    if (s.charAt(st.peek()) == '(') st.pop();
                    else { // no match and pushed to stack
                        st.push(i);
                    }
                }
            }
        }
        //why ???, think the example (()
        st.push(s.length());  
        //for (auto x: st) cout << x << endl;

        int longest = 0;
        int right = st.pop();
        
        while (!st.isEmpty()) {
            int left = st.pop();
            //start ... st[i],    1 23 4 . 4-1-1
            longest = Math.max(right - left-1, longest);
            right = left;//update
        }
        longest = Math.max(right, longest);
        return longest;

    }
}
