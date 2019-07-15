//grandyang dp, 36ms, faster than 32%
//shaun modified to his own style
// dp[i][j] store bool palindrome substring from i to j
// compute in the order of substring len
//runtime 32ms, faster than 28%, mem less than 50%
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0;
        //dp[i][j] substring i to j is palindrome
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            ++res;
        }
        //for shorter string to longer
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len -1 < n; ++i) {
                int j = i + len -1;
                dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
                if (dp[i][j]) ++res;
            }
        }
        return res;
    }
};  
