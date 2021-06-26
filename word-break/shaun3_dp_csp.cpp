//cspiration idea, dynamic programming
//shuan code from memory, first in java, then c++
//runtime 16ms, faster than 61%, mem less than 21%
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        set.insert(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1); //dp[i] indicates if substr from 0 to i-1 can be broken
        dp[0] = true;
        //substr end i from 0 to n-1 
        for (int i = 1; i <=n; ++i) {
            //0 -- j --i
            for (int j = 0; j < i; ++j) {
                //0 to j-1, from j to i
                // end index = i-1, len = (i-1)-j+1 = i-j
                string word = s.substr(j,i-j);
                if (set.count(word) && dp[j]) {
                    dp[i] = true;
                    break;
                }
                
            }
        }
        return dp[n];
    }
};


