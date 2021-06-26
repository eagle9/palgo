/*
Time complexity: O(n)
Space complexity: O(1)

hua dp idea hint
*/
//shaun code via hua's dp idea hint
//accepted after 2 bug fixes
//runtime 0ms, faster than 100%, mem less than 83%
//cutting angle,  valid or not, last 1 char decode + 1 char shorter string decode,  or last 2 char combine decode + 2 char shorter string decode
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() ) return 0;
        if (s[0] == '0') return 0;
        if (s.length() == 1) return 1;
        
        //now s.length >= 2
        const int n = s.length();
        
        vector<int> dp(n+1); //decode ways for s0 len n
        dp[0] = 1; //empty string
        dp[1] = isvalid(s[0])? 1: 0;
        for (int i = 2; i <=n; ++i) {
            //int dp = 0;  //ans for current length
            if (!isvalid(s[i-1]) && !isvalid(s[i - 2], s[i-1])) return 0;
			//case 1, last char can be decoded
            if (isvalid(s[i-1])) dp[i] += dp[i-1];
			//case 2, last 2 chars can be combined and decoded
            if (isvalid(s[i - 2], s[i-1])) dp[i] += dp[i-2]; // dp_2 and last two chars combined can be decoded separately
            
        }
        //return dp_1;
        return dp[n];
    }

    //hua's rolling array to reduce dimension
    //shaun modified for more natural reading
    //runtime 4ms, faster than 84%, mem less than 71%
    int numDecodings2(string s) {
        if (s.empty() ) return 0;
        if (s[0] == '0') return 0;
        
        if (s.length() == 1) return 1;
        //now s.length >= 2
        const int n = s.length();
        int dp_1 = 1; //ans for 1 char shorter 
        int dp_2 = 1; //ans for 2 char shorter
        
        for (int i = 1; i < n; ++i) {
            int dp = 0;  //ans for current length
            if (!isvalid(s[i]) && !isvalid(s[i - 1], s[i])) return 0;
			//case 1, last char can be decoded
            if (isvalid(s[i])) dp += dp_1; //dp_1 and last char can be decoded separately
            
			//case 2, last 2 chars can be combined and decoded
            if (isvalid(s[i - 1], s[i])) dp += dp_2; // dp_2 and last two chars combined can be decoded separately
            //now roll array
            dp_2 = dp_1;
            dp_1 = dp;
        }
        return dp_1;
    }
    
    
    bool isvalid(const char c) { return c != '0'; }
    //char c1 and c2 combine can be decoded? 
    bool isvalid(const char c1, const char c2) { 
        const int num = (c1 - '0')*10 + (c2 - '0');
        return num >= 10 && num <= 26;
    }
};

