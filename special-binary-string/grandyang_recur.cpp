/*
grandyang, recursion
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Special Binary String.
Memory Usage: 9.2 MB, less than 41.18% of C++ online submissions for Special Binary String.
*/
class Solution {
public:
    string makeLargestSpecial(string S) {
        int cnt = 0, i = 0;
        vector<string> v;
        string res = "";
        for (int j = 0; j < S.size(); ++j) {
            cnt += (S[j] == '1') ? 1 : -1;
            if (cnt == 0) {
                v.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(v.begin(), v.end(), greater<string>());
        for (int i = 0; i < v.size(); ++i) res += v[i];
        return res;
    }
};
