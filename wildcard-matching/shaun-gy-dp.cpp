//grandyang 2d dp 
//match s len i substring with p's len j substring
// then critical dealing with *
//compare with regular expression matching, similar cutting angle
//runtime 92ms, faster than 41%, mem less than 61%
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        //dp[i][j]  s0 len i matches p0 len j 
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        //complete init the first row, i = 0, only **** can match
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
        }
        for (int i = 1; i <= m; ++i) {  //ij from 1 because i-1 and j-1 are used
            for (int j = 1; j <= n; ++j) {
                //case 1
                //s:         i-2    <<i-1>>
                //p:         *
                //case 2
                //s:         i-1
                //p:    j-2  <<*>>
                if (p[j - 1] == '*') {
                    //          case 1           case2
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    //dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '?') 
                        dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

