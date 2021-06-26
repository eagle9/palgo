//shaun code upon huahua 2d dp hint, compute order from laioffer hint
//accepted after two hints
//runtime 64ms, faster than 83%, mem less than 58%

//computer order:
//       0   1    2  3
//    0
//    1           v  x
//    2           v  v
//so to computer x, the order should be from left to right, and down to up
// 1*3, if s[1] == s[3], we need dp[2][2]
//  s[1]!= s[3],  we need either dp[2][3] or dp[1][2]
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        //dp[i][j]   answer for s[i] to s[j]
        vector<vector<int>> dp(n, vector<int>(n));
        
        //tabulate dp, which order? 
        for (int i = n-1; i >=0; --i) {
            for (int j = i; j <= n-1; ++j) {
                /*
                if (i > j) {
                    //dp[i][j] = 0;
                    continue;
                }*/
                if (i == j) {
                    dp[i][j] = 1;
                    continue;
                }
                //ij   i*j i**j
                if (s[i] == s[j]) {
                    dp[i][j] = i+1 > j-1? 2: dp[i+1][j-1]+2;
                }
                else {
                    //s[i]****s[j], remove s[i] or s[j]
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
};
