/*Time complexity: O(|s| * |t|)
Space complexity: O(|s| * |t|)
huahua dp cpp, runtime error
shaun translate to java, accepted
runtime 4ms, faster than 90%, mem less than 96%
*/
class Solution {
    public int numDistinct(String s, String t) {
        int ls = s.length(), lt = t.length();
        //dp[i][j] -- number of distinct subseq using s 0 to j-1 to construct t 0 to i-1
        //try to derive dp[i][j] from i-1,j-1 case
        int [][] dp = new int[lt+1][ls+1];
        
        //init i = 0, to construct empty string, number is 1
        for (int j = 0; j <= ls; j++)
            dp[0][j] = 1;
        //init j = 0, if i!=0, empty string to contruct non empty subseq, impossible, so 0, already init with 0 default value
        
        for (int i  = 1; i <= lt; i++) {
            for (int j = 1; j <= ls; j++) {
                //last char of s, s[j-1] used or not
                //not used, dp[i][j-1] -- construct t0 to i-1 with s0 to sj-2
                //used when last char ==, boils down dp[i-1][j-1], then append last char to each dp[i-1][j-1] subseq
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
