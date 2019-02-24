/*
Runtime: 572 ms, faster than 91.67% of C++ online submissions for Expression Add Operators.
Memory Usage: 104 MB, less than 100.00% of C++ online submissions for Expression Add Operators.
huahua dfs1

*/
class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> ans;
    dfs(num, target, 0, "", 0, 0, &ans);
    return ans;
  }
private:
  void dfs(const string& num, const int target,  // input
           int pos, const string& exp, long prev, long curr, // state
           vector<string>* ans) {  // output
    if (pos == num.length()) {
      if (curr == target) ans->push_back(exp);
      return;
    }
    
    for (int l = 1; l <= num.size() - pos; ++l) {
      string t = num.substr(pos, l);    
      if (t[0] == '0' && t.length() > 1) break; // 0X...
      long n = std::stol(t);
      if (n > INT_MAX) break;
      if (pos == 0) {
        dfs(num, target, l, t, n, n, ans);
        continue;
      }
      dfs(num, target, pos + l, exp + '+' + t, n, curr + n, ans);
      dfs(num, target, pos + l, exp + '-' + t, -n, curr - n, ans);
      dfs(num, target, pos + l, exp + '*' + t, prev * n, curr - prev + prev * n, ans);
    }    
  }
};
