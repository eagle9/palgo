//grandyang dfs, runtime 8ms, faster than 51%
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int cnt1 = 0, cnt2 = 0;
        for (char c : s) {
            cnt1 += (c == '(');
            if (cnt1 == 0) cnt2 += (c == ')');
            else cnt1 -= (c == ')');
        }
        helper(s, 0, cnt1, cnt2, res);
        return res;
    }
    void helper(string s, int start, int cnt1, int cnt2, vector<string>& res) {
        if (cnt1 == 0 && cnt2 == 0) {
            if (isValid(s)) res.push_back(s);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            if (i != start && s[i] == s[i - 1]) continue;
            if (cnt1 > 0 && s[i] == '(') {
                helper(s.substr(0, i) + s.substr(i + 1), i, cnt1 - 1, cnt2, res);
            }
            if (cnt2 > 0 && s[i] == ')') {
                helper(s.substr(0, i) + s.substr(i + 1), i, cnt1, cnt2 - 1, res);
            }
        }
    }
    bool isValid(string t) {
        int cnt = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == '(') ++cnt;
            else if (t[i] == ')' && --cnt < 0) return false;
        }
        return cnt == 0;
    }
};
