//grandyang 2d dp 
//match s len i substring with p's len j substring
// then critical dealing with *
//compare with regular expression matching, similar cutting angle
//cutting, 2d dp with s len i and p len j
//consider transition f(i,j) = combine result with f(i,j-1), f(i-1, j) and f(i-1,j-1)
//runtime 92ms, faster than 41%, mem less than 61%
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        //dp[i][j]  s0 len i matches p0 len j, init value is false
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        
        //complete init the first row, i = 0, only **** can match
        //init for dp[0][...] is key, otherwise wrong answer, why? 
        //because transition function f(i,j)  is dervied from f(i-1,j), f(i,j-1) and f(i-1,j-1)
        //so we need to init for i=0, true only for when p = "*****"
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
        }
        //how about j=0, pattern is empty, s must be empty too, so only dp[0][0] is true, other dp[..][0] remains to be false
        
        for (int i = 1; i <= m; ++i) {  //ij from 1 because index i-1 and j-1 are used
            for (int j = 1; j <= n; ++j) {
                
                if (p[j - 1] == '*') {
                    //case 1: s len i matches p len j-1, * match empty tring, bingo
                    //case 2, s len i-1 matches p len j, * match any sequence, bingo
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

