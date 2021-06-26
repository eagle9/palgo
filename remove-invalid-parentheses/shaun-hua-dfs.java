//hua dfs idea, shaun has understood
//cutting angle:  first figure out how left and right parenthesis need to be removed. 
// then dfs cursor recursion, from left to right of the string, try all possible removals
//   to avoid repetition
//Runtime: 4 ms, faster than 68.26% of Java online submissions for Remove Invalid Parentheses.
//Memory Usage: 39.9 MB, less than 33.30% of Java online submissions for Remove Invalid Parentheses.

class Solution {
    public List<String> removeInvalidParentheses(String s) {
        int left = 0; //minimum number of left ( to remove
        int right = 0; //minimum number of right ) to remove
        for (char ch : s.toCharArray()) {
              if (ch == '(') left++;
              if (ch ==')') {
                  if (left ==0) right++; //no match, this ) to be removed
                  else left--; //matched
              }
        }
        List<String> ans = new ArrayList<>();
        dfs(s, 0, left, right, ans);
        return ans;
    }
    
    private boolean isValid(String s) {
        int count = 0; //count of ( to be matched by )
        for (char ch : s.toCharArray()) {
            if (ch == '(') ++count;
            if (ch == ')') {
                if (count == 0) return false;
                --count; //matched one (
            }
        }
        return count == 0;
    }
    
    //why dfs recur, because remove 1, similar problem
    //use parameter ans to catch all valid strings
    // l/r: number of left/right parentheses to remove.
    void dfs(final String s, int start, int l, int r, List<String> ans) {
        // Nothing to remove.
        //recur exit, done removal, check if need to add ans
        if (l == 0 && r == 0) {
          if (isValid(s)) ans.add(s);
          return;
        }

        //try all cases to remove 1
        for (int i = start; i < s.length(); ++i) {
          // We only remove the first parenthes if there are consecutive ones to avoid duplications.
          //skip char == prev char
          if (i != start && s.charAt(i) == s.charAt(i - 1)) continue;

          //only check ( or )
          if (s.charAt(i) == '(' || s.charAt(i) == ')') {
            String curr = s.substring(0,i) + s.substring(i+1); //remove ith char
            if (r > 0 && s.charAt(i) == ')')  //remove right ) first
              dfs(curr, i, l, r - 1, ans);
            if (l > 0 && s.charAt(i) == '(')
              dfs(curr, i, l - 1, r, ans);
          }
        }
  }
}

