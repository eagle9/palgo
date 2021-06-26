//grandyang dp idea, dp is actually better than recur, cleaner transition function 
//the hard point is *, case 1 to remove c* from p and match s and p
//case 2 or match c with end of s, remove the end char from s,  and match with p

//runtime 4ms, faster than 97%, mem less than 77%
/*
lt transition hint:
1.  P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
2.  P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
3.  P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.

*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        //dp[i][j]  s len i matched by p len j? 
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (j >= 2 && p[j - 1] == '*') { //must exist a char before *
                    //s:     i-2  i-1
                    //p:          j-3  <<j-2   *>>    <<>> cut
                    // use p[j-2] 0 times
                    // boils down s0 len i matches p0 len j-2
                    dp[i][j] = dp[i][j] || dp[i][j-2];
                    
                    // use p[j-2] match s[i-1] once
                    // s:            i-2  <<i-1>>
                    // p:         j-2 *  <<p[j-2]>>  copy, match and cut 
                    // p:              
                    //last char of s matched with j-2, shorten s by 1
                    if(i > 0 && (p[j - 2] == s[i - 1]|| p[j - 2] == '.')) {
                         dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                    
                } else {
                    //p[j-1] != *
                    //s:      <<i-1>>
                    //p:      <<j-1>>  match and cut
                    //p:       <<.>>
                    if (i > 0 && j> 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.')) {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
