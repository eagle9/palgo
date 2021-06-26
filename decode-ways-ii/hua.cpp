/*
hua dp, similar dp idea as 1, shaun read and understand, cutting angle to see recurrence  
dp's advantage, when rolling dp array possible, dp saves a lot of space
key points: to figure out all the details
Runtime: 48 ms, faster than 96% of C++ online submissions for Decode Ways II.
Memory Usage: 15 MB, less than 91% of C++ online submissions for Decode Ways II.
*/
class Solution {
public:
    int numDecodings000(string s) {
        if (s.empty()) return 0;        
        //           dp[-1]  dp[0], dpi depends on dpi-1 and dpi-2
        long dp[2] = {1, ways(s[0])};  
        for (int i = 1; i < s.length(); ++i) {
            long dp_i = ways(s[i]) * dp[1] + ways(s[i - 1], s[i]) * dp[0];
            dp_i %= kMod;
            dp[0] = dp[1];
            dp[1] = dp_i;
        }
        return dp[1];
    }
    //if you don't understand dp[-1]=1, try shaun's version
    int numDecodings(string s) {
        if (s.empty()) return 0;        
        //           dp[-1]  dp[0], dpi depends on dpi-1 and dpi-2
        long a = ways(s[0]);
        if (s.size() == 1) return a;
        long b = a*ways(s[1])+ ways(s[0],s[1]);
        for (int i = 2; i < s.length(); ++i) {
            long dpi = ways(s[i]) * b + ways(s[i - 1], s[i]) * a;
            dpi %= kMod;
            a = b;
            b = dpi;
        }
        return b;
    }
private:
    static constexpr int kMod = 1000000007;    
    
    int ways(char c) {
        if (c == '0') return 0;
        if (c == '*') return 9;   //* can be 1 to 9
        return 1; //1-9,  1 way
    }
   
	//decode c1c2 as a whole 
	//from problem statement, * to 1-9
    int ways(char c1, char c2) {
		//**: 11-19, 21-26,  9+6=15
        if (c1 == '*' && c2 == '*') 
            return 15; 

		//*d   [1/2 d]   1d    2d
        if (c1 == '*') { //first*, 
          return (c2 >= '0' && c2 <= '6') ? 2 : 1;
        } 
		// d*
		else if (c2 == '*') {
            switch (c1) {
                case '1': return 9;
                case '2': return 6;
                default: return 0;
            }
        } 
		//dd
		else {
            int prefix = (c1 - '0') * 10 + (c2 - '0');
            return prefix >= 10 && prefix <= 26?1:0;
        }        
    }
};
