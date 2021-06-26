/*
Runtime: 32 ms, faster than 100.00% of C++ online submissions for Expression Add Operators.
Memory Usage: 17 MB, less than 100.00% of C++ online submissions for Expression Add Operators.

hua dfs2 with O(n) space complexity

*/
class Solution {
public:
  vector<string> addOperators(string num, int target) {
    vector<string> ans;
    string exp(num.length() * 2, '\0');    
    dfs(num, target, 0, exp, 0, 0, 0, &ans);
    return ans;
  }
private:
  void dfs(const string& num, const int target,
           int pos, string& exp, int len, long prev, long curr,
           vector<string>* ans) {    
    if (pos == num.length()) {      
      if (curr == target) ans->push_back(exp.substr(0, len));
      return;
    }
    
    long n = 0;
    int s = pos;
    int l = len;
    if (s != 0) ++len;    
    while (pos < num.size()) {      
      n = n * 10 + (num[pos] - '0');
      if (num[s] == '0' && pos - s > 0) break; // 0X... invalid number
      if (n > INT_MAX) break; // too long
      exp[len++] = num[pos++];
      if (s == 0) {
        dfs(num, target, pos, exp, len, n, n, ans);
        continue;
      }
      exp[l] = '+'; dfs(num, target, pos, exp, len, n, curr + n, ans);
      exp[l] = '-'; dfs(num, target, pos, exp, len, -n, curr - n, ans);
      exp[l] = '*'; dfs(num, target, pos, exp, len, prev * n, curr - prev + prev * n, ans);
    }
  }
};
