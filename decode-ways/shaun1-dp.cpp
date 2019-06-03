//shaun's original idea, overflow first due to 10101... case
//added code to deal with 0,   fixed 12 -> (1,2) is 1 decode, rather than 2
//accepted, runtime 4ms, faster than 100%
//my own idea, but i totally forgot after two month
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        
        vector<int> dp(n); //dp[i] number of decode ways s[0 .. i]
        if (s[0] != '0') {
            dp[0] ++;
        }
        
        if (n == 1) return dp[n-1]; //single char
        
        if (s[0] != '0' && s[1] != '0') {
            dp[1] = 1;
        }
        if (s.substr(0,2) <= "26" && s.substr(0,2) >= "10") dp[1]++;
        for (int i = 2; i < n; ++i) {
            //      + s[i]  s[i-1..i] 
            if (s[i] != '0')
                dp[i] = dp[i-1];
            if (s.substr(i-1,2) <= "26"  && s.substr(i-1,2) >= "10")
                dp[i] += dp[i-2];
        }
        
        return dp[n-1];
    }
};
