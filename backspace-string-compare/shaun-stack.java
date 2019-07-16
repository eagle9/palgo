class Solution {
    //beats 53% using stack 
    //idea https://blog.csdn.net/carbon06/article/details/80586204
    /*key points
    // 1) java stack pop throws emptyStackException, must sure it is not empty before you pop
    // 2) if (cond1)
            if (cond2)  A  //one line if statement
          else
            B
        B match if cond2, not if cond1
        conclusion: to be safe, always use {} with if and else
        
    //
    
    */
    public boolean backspaceCompare(String S, String T) {
        Stack<Character> s1 = new Stack<>();
        Stack<Character> s2 = new Stack<>();
        
        char [] s = S.toCharArray();
        char [] t = T.toCharArray();
        for (int i = 0; i < s.length; i++ ) {
            //System.out.println("s " + s[i] + " size=" + s1.size());
            if (s[i] == '#') {
                if (!s1.isEmpty()) s1.pop();
            }
            else {
                s1.push(s[i]);
                //System.out.println("push");
            }
        }
        
        for (int i = 0; i < t.length; i++ ) {
            //System.out.println("t " + t[i] + " size=" + s2.size());
            /*initially i wrote
            if (t[i] == "#") 
                if (!s2.isEmpty()) s2.pop()
            else   //else will match with the 2nd if, that's why is not correct
                s2.push(t[i])
            */
            if (t[i] == '#') {
                if (!s2.isEmpty()) s2.pop();
            }
            else
                s2.push(t[i]);
        }
        //System.out.println(s1.size() + " " + s2.size());
        int n = s1.size();
        if (n != s2.size()) return false;
        for (int i = 0; i < n; i++) {
            char a = s1.pop();
            char b = s2.pop();
            //System.out.println(a + " " + b);
            if (a != b)
                return false;
        }
        return true;
    }
}
