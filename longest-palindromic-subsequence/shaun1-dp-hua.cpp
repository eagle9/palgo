//hua 2d dp idea, computer order is from len 1 to n
//found out that len depends on len-1 and len-2
//accepted after adding "if (j > n-1) continue" j boundary check
//runtime 76ms, faster than 73%, mem less than 44%
class Solution1 {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        //computer order, len 1 to n
        for (int len = 1; len <= n; ++len) { //len from 1 to n
            for (int i = 0; i <= n-1; ++i) { //start from 0 to n-1
                //end index j
                int j = i + len -1; //len = 1,j = i, len = 2, j=i+1
                if (j > n-1) continue;
                if (len == 1) {
                    dp[i][j] = 1;
                    continue;
                }
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

//reduce dimension
//shaun coded from hua's 3 array hint
//accepted after 1 bug fix, the think angle is computer order from shorter len to longer len
//runtime 52ms, faster than 93%, mem less than 95%
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> dp0(n); //for len, start from i
        vector<int> dp1(n); //for len-1, start from i
        vector<int> dp2(n); //for len-2, start from i
        
        //computer order, len 1 to n
        for (int len = 1; len <= n; ++len) { //len from 1 to n
            for (int i = 0; i <= n-1; ++i) { //start from 0 to n-1
                //end index j
                int j = i + len -1; //len = 1,j = i, len = 2, j=i+1
                if (j > n-1) continue;
                if (len == 1) {
                    dp0[i] = 1;
                    continue;
                }
                if (s[i] == s[j]) {
                    dp0[i] = dp2[i+1]+2;
                }
                else {
                    //s[i]****s[j], remove s[i] or s[j]
                    dp0[i] = max(dp1[i+1], dp1[i]);
                }
            }
            //dp2 dp1 dp0
            //    dp2 dp1
            dp2.swap(dp1); //dp2 = dp1
            dp1.swap(dp0); //dp1 = dp0;
            
        } 
        return dp1[0];
        
    }
};
