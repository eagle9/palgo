//grandyang dp
//cuting break s into left and right, if right in dict, then left is smaller problem
// [0,i) ----> [0,j), [j,i)   ---> j from 0 to j <= i-1
//runtime 16ms, faster than 64%, mem less than 15%
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n  = s.size();
        
        vector<bool> dp(n+1);   //dp[i]   [0,i) can break, dp index 0 to n
        dp[0] = true; //empty string
        
        for (int i = 0; i <= n; ++i) {
            //break [0,i) : [0,j) + [j,i)
            //including 1 break into empty and whole, why? let right be all substring of s, except empty 
            for (int j = 0; j < i; ++j) {
                const string & right = s.substr(j, i-j);
                if (dp[j] && wordSet.count(right)) {
                    dp[i] = true;
                    break; //no longer need to try other break
                }
            }
        }
        return dp[n];
    }
};
