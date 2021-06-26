//hua dfs idea, shaun has understood
//cutting angle:  first figure out how left and right parenthesis need to be removed. 
// then dfs cursor recursion, from left to right of the string, try all possible removals
//   to avoid repetition
//runtime 4ms, faster than 97%, mem less than 77%
class Solution {
public:
  vector<string> removeInvalidParentheses(const string& s) {        
    int left = 0; //minimum number of left ( to remove
    int right = 0; //minimum number of right ) to remove
 
    for (const char ch : s) {
      if (ch == '(') left++;
      if (ch ==')') {
          if (left ==0) right++; //no match, this ) to be removed
          else left--; //matched
      }
    }
 
    vector<string> ans;
    dfs(s, 0, left, right, ans);
    return ans;
  }
private:
  bool isValid(const string& s) {
    int count = 0; //count of ( to be matched by )
    for (const char ch : s) {
      if (ch == '(') ++count;
      if (ch == ')') {
          if (count == 0) return false;
          --count; //matched one (
      }
      //if (count < 0) return false;
    }
    return count == 0;
  }
 
  // l/r: number of left/right parentheses to remove.
  void dfs(const string& s, int start, int l, int r, vector<string>& ans) {
    // Nothing to remove.
    if (l == 0 && r == 0) {
      if (isValid(s)) ans.push_back(s);
      return;
    }
 
    for (int i = start; i < s.length(); ++i) {
      // We only remove the first parenthes if there are consecutive ones to avoid duplications.
      //skip char == prev char
      if (i != start && s[i] == s[i - 1]) continue;
 
      if (s[i] == '(' || s[i] == ')') {
        string curr = s; //make a copy
        curr.erase(i, 1); //c++ string is dynamic container
        if (r > 0 && s[i] == ')')  //remove right ) first
          dfs(curr, i, l, r - 1, ans);
        else if (l > 0 && s[i] == '(')
          dfs(curr, i, l - 1, r, ans);
      }
    }
  }
};
