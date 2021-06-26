//grandyang 2d dp
//cutting substring i to j 2d dp, compute in the order of substring len
// put for len at the first loop
//i == j?   the substring inside is palindrome? 

//dp[i][j] substring i to j is palindrome
//compute in the order of substring len
//runtime 168ms, faster than 31%, mem less than 43%

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int n = s.size();
        
        //int dp[n][n] = {0};  //faster than 27%
        bool dp[n][n] = {false};
        //vector<vector<int>> dp(n, vector<int>(n)); //faster than 20%
        int left = 0, longest = 0;
        //substring start from i
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true; //len = 1
            longest = 1;
            left = i;
        }
        //for (int i = 0; i < n; ++i) {
        //    for (int len = 2; i+len-1 < n; ++len) { ---> bug
        for (int len =2; len <= n; ++len) {
            for (int i = 0; i +len -1 < n; ++i) {
                //start i,  end j, 
                int j = i + len -1;
                
                //i+1 > j-1 ==> j - i < 2
                //i+1 == j-1 ==> j -2 == 2
                dp[i][j] = (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1]));
                if (dp[i][j] && longest < len) {
                    longest = len;
                    left = i;
                }
            }
        }
        return s.substr(left, longest);
    }
};
