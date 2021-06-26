//shaun's own code after knowing to use stack
//think like a computer
//Feb 5 2019
//runtime 4ms, faster than 99%
class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        char [] c = s.toCharArray();
        for (int i = 0; i < c.length; i++) {
            if (c[i] == '(' || c[i] == '{' || c[i] == '[') 
                st.push(c[i]);
            else {
                if (st.isEmpty()) return false; //no matching left par
                char left = st.pop();
                if (c[i] == ')' && left != '(') return false;
                if (c[i] == '}' && left != '{') return false;
                if (c[i] == ']' && left != '[') return false;
                
            }
        }
        //pass all tests
        //key to check if stack is empty after iteration of all chars
        if (st.isEmpty()) return true;
        else return false;
    }
}
