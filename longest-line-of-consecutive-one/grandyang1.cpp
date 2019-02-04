//grandyang brute forece, runtime 236ms, faster than 9%
//
class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty() || M[0].empty()) return 0;
        int res = 0, m = M.size(), n = M[0].size();
        for (int i = 0; i < m; ++i) { // Check horizontal
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (M[i][j] == 1) res = max(res, ++cnt);
                else cnt = 0;
            }
        }
        for (int j = 0; j < n; ++j) {
            int cnt = 0;
            for (int i = 0; i < m; ++i) { // Check vertical
                if (M[i][j] == 1) res = max(res, ++cnt);
                else cnt = 0;
            }
        }
        //not easy to come up the diagonal path
        for (int i = 0; i < m + n - 1; ++i) {
            int cnt1 = 0, cnt2 = 0;
            for (int j = i; j >= 0; --j) {
                if (i - j < m && j < n) { // Check diagonal
                    if (M[i - j][j] == 1) res = max(res, ++cnt1);
                    else cnt1 = 0;
                }
                int t = m - 1 - i + j;
                if (t >= 0 && t < m && j < n ) { // Check anti-diagonal
                    if(M[t][j] == 1) res = max(res, ++cnt2);
                    else cnt2 = 0;
                }
            }
        }
        return res;
    }
};
