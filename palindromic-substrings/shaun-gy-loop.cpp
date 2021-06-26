//grandyang iteration, 12ms, faster than 64%
// all center index, expand to various length, and count
// key is to know 2 cases, ii and i&i+1
class Solution1 {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        int n = s.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            helper(s, i, i, res);
            helper(s, i, i + 1, res);
        }
        return res;
    }
    void helper(string s, int i, int j, int& res) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            --i; ++j; ++res;
        }
    }
};

