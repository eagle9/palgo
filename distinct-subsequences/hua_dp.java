/*Time complexity: O(|s| * |t|)
Space complexity: O(|s| * |t|)
huahua dp cpp, runtime error
shaun translate to java, accepted
Runtime: 4 ms, faster than 95.21% of Java online submissions for Distinct Subsequences.
Memory Usage: 34.5 MB, less than 85.51% of Java online submissions for Distinct Subsequences.
*/
class Solution {
    public int numDistinct(String s, String t) {
        int ls = s.length(), lt = t.length();
        int [][] dp = new int[lt+1][ls+1];
        //fill(begin(dp[0]), end(dp[0]), 1);  
        for (int j = 0; j <= ls; j++)
            dp[0][j] = 1;
        
        for (int i  = 1; i <= lt; i++) {
            for (int j = 1; j <= ls; j++) {
                dp[i][j] = dp[i][j - 1] + (t.charAt(i - 1) == s.charAt(j - 1) ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[lt][ls];
        
    }
}


/*

class Solution {
public:
  int numDistinct(string s, string t) {
    int ls = s.length();
    int lt = t.length();
    vector<vector<int>> dp(lt + 1, vector<int>(ls + 1));
    fill(begin(dp[0]), end(dp[0]), 1);        
    for (int i = 1; i <= lt; ++i)
      for (int j = 1; j <= ls; ++j)
        dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);        
    return dp[lt][ls];
  }
};
*/
