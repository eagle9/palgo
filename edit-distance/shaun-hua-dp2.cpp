//hua dp, cutting angle, think len of two words, and cases to reduce the problem to shorter string
//shaun is able to code and get it accepted after 1 bug fix
//runtime 12ms, faster than 86%, mem less than 56%
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        //dp[i][j] --- edit distance word1 from 0 len i and word2 from 0 len j
        //we need to consider len = 0, 1, ..., n
        //now we can see dp array size is len1+1  * len2 + 1
        vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));
        //case 1, second word is empty, j ==0, the distance is word1's len i
        for (int i = 0; i <= len1; ++i) dp[i][0] = i;
        //case 2, first word is empty
        for (int j = 0; j <= len2; ++j) dp[0][j] = j;
        
        //case 3, look at the ending char of both words
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                //case a -- replace ending char
                int cost = (word1[i-1] == word2[j-1])? 0 : 1;
                dp[i][j] = dp[i-1][j-1] + cost;
                //case b -- append 1 char to word1
                dp[i][j] = min(dp[i][j], dp[i-1][j]+1);
                //case c -- delete 1 char from word1
                dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                
            }
        }
        
        //return dp[len1-1][len2-1]; //bug 1
        return dp[len1][len2];
        
    }
};
