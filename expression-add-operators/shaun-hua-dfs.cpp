//hua dfs idea, 
// runtime 456ms, faster than 78%, mem less than 60%
//cutting angle move pos cursor from 0 to num.size()
//         pos
//num: exp  | t 
//to deal with * order priority, use prev to track tail expression
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(num, target, 0, "", 0, 0, ans);
        return ans;
    }
private:
    //break the string num with cursor pos from 0
    //        pos
    //num: exp | t ...
    //     curr
    //cursor ends it run at num.length()
    //string& exp is the growing candidate
    //use prev to track prev segment value, for *
    //use curr to track exp value
    void dfs(const string& num, const int target,  // input
           int pos, const string& exp, long prev, long curr, // state
           vector<string>& ans) {  // output
    if (pos == num.length()) {
        if (curr == target) ans.push_back(exp);
        return;
    }
    
    //ending index = pos + len - 1 <= nums.size()-1 ---> len <= num.size()-pos
    //try all possible substr/number after exp
    for (int len = 1; len <= num.size() - pos; ++len) {
        string t = num.substr(pos, len); 
        if (t[0] == '0' && t.length() > 1) break; // 0X...
        long n = std::stol(t);
        if (n > INT_MAX) break;
        if (pos == 0) {
            dfs(num, target, len, t, n, n, ans);
            continue;
        }
        dfs(num, target, pos + len, exp + '+' + t, n, curr + n, ans);
        dfs(num, target, pos + len, exp + '-' + t, -n, curr - n, ans);
        dfs(num, target, pos + len, exp + '*' + t, prev * n, curr - prev + prev * n, ans);
    }    
  }
};
