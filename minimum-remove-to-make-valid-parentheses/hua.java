//not understood
class Solution {
    public String minRemoveToMakeValid(String s) {
        int close = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == ')') close++;
        }
        int open = 0;
        StringBuilder ans = new StringBuilder();    

        for (char c : s.toCharArray()) {
          if (c == '(') {
            if (open == close) continue;
            ++open;
          } 
          else if (c == ')') {
            --close;
            if (open == 0) continue;
            --open;
          }
          ans.append(c);
        }    
        return ans.toString();
    }
}
