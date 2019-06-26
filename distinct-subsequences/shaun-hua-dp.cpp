//hua dp 2d with 2 strings, shaun read, understand, modified
//shaun rewrite the code strict with dp template,  addded thinking about initialization, compute order
//runtime 0ms, faster than 100%, mem less than 39%
//cutting angle, look at ending chars and reduce to smaller strings
//actually not that hard
class Solution {
public:
    int numDistinct(string s, string t) {
        int ls = s.length();
        int lt = t.length();
        //vector<vector<int>> dp(lt + 1, vector<int>(ls + 1));
        //dp[i][j]  s0 len i number of subsequence to t0 len j
        //s0 ... i-2 i-1
        //t0 ... j-2 j-1
        //s[i-1] == t[j-1], use s[i-1] taken as the last char of the equal subseq
        // !=, then s[i-1] useless, just find in s[0..i-2]
        
        vector<vector<long>> dp(lt + 1, vector<long>(ls + 1));
        
        
        //computer order:
        // i-1,j-1
        //  i,j-1       i,j
        //i == 0, target string is empty, we take an empty string from s, skip all chars in s
        //fill(dp[0].begin(), dp[0].end(), 1);
        for (int j = 0; j <= ls; ++j) dp[0][j] = 1; //if you don't know about container fill function
        //how about dp[?][0], s is empty, if t is not empty, then no way to make subseq from s, no chars
        //dp[][] already init to 0
        
        
        //according to the transition function, i-1 & j-1 will be used.
        //so we will start the loop from i = 1 and j = 1
        
        for (int i = 1; i <= lt; ++i)
          for (int j = 1; j <= ls; ++j) {
              //case1, we can use last char in the subseq
              //use s[j-1] for t[i-1], or not use it
              if (s[j - 1] == t[i-1]) {
                  //dp[i][j] = dp[i - 1][j - 1]  bug 1-- can use, but you can also not use it, so two cases, both cases contribute
                  dp[i][j] = dp[i - 1][j - 1] + dp[i][j-1];
              }
              else //case2: can not use s[j-1], boils down 0.. s[j-2] --> t[0-j-1]
                  dp[i][j] = dp[i][j - 1];
          }
            //dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);     
        return (int) dp[lt][ls];
    }
};
