/*
idea forming may 17 2020
3[sadjfjdjsf]
reps number could be multiple digits
reps number quality string inside [] find the substring, and do recur
how to find the string each right after the rep number, first [,   depth -1
see [-1, see ] +1, when return to 0 uppon ], get the string, call helper, concat 


2019 idea
//shaun's own idea and code, accepted after fixes
//fix 1:   repetition number can be 100, not just single digit number
//fix 2:  c++ init string with length
//fix 3: some typos
//runtime 4ms, faster than 100%, mem less than 95%
//the breakthough is made to run your idea with some examples, think with force and clarity
//cutting ---- use stack to process nested structure, push, then check top, pop it, process it, then push back, one tricky details is to process the number that could be multiple chars


//cutting my original idea is to deal with the deepest matching [] just seen, then repeat the string inside
//with the number before [
Runtime: 2 ms, faster than 51.18% of Java online submissions for Decode String.
Memory Usage: 37.6 MB, less than 5.68% of Java online submissions for Decode String.

*/
class Solution {
    public String decodeString(String s) {
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); ++i) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                st.push(c);
            }else if (c == '[') {
                st.push(c);
            }else if (Character.isAlphabetic(c)) {
                st.push(c);
            }else if (c == ']') { 
                List<Character> temp = new LinkedList<>();
                //pop chars till first previous [
                while (!st.isEmpty() && st.peek() != '[') {
                    char c2 = st.pop();
                    temp.add(0,c2);
                }
                //st.top == '[' now, pop it
                st.pop();
                
                //now look for the number(reps)
                int n = 0, base = 1;
                while (!st.isEmpty() && Character.isDigit(st.peek())) {
                    int digit = st.pop() - '0';
                    n += digit*base;
                    base*=10;
                }
                
                //push vector<char> temp back to stack n reps
                for (int t = 0;  t< n; t++) {
                    for (int j = 0; j < temp.size(); ++j) {
                        st.push(temp.get(j));
                    }
                }
            }
        }
        int n = st.size();
        char [] res = new char[n];
        int i = n-1;
        while (!st.isEmpty()) {
            res[i--] = st.pop();
        }
        return String.valueOf(res);

    }
};

