//grandyang dp, shaun came up with similar idea, not clear about 2d p to store 
//palindrome substring yet
//runtime 24ms, faster than 68%, mem less 59%
class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        //substring from i to j palindromic? 
        vector<vector<bool>> p(n, vector<bool>(n));
        //min number of cuts
        vector<int> dp(n);
        //for each ji j<= i
        for (int i = 0; i < n; ++i) {
            //dp[i] = i; // ans for string 0 to i, i chars, max i cuts
            dp[i] = INT_MAX; //okay too
            // 0 .. j-1  j.. i, get dp[i] from smaller j, all cases 
            //j <= i, 1 single char
            // j..i is palindromic, then just 1 more cut after dp[j-1]
            // dp[i]  0 .. i-1
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (i - j < 2 || p[j + 1][i - 1])) {
                    p[j][i] = true;
                    
                    //first write this, but we found j-1 index, what if j ==0, so natural to come up j==0 case
                    //dp[i] = min(dp[i], dp[j - 1] + 1); 
                    //j == 0, 0 .. i palindrome, 0 cuts
                    
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n - 1]; // string 0 to n-1
    }
};
