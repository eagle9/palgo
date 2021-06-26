//runtime 9ms, faster than 45%
//cspiration idea, dynamic programming
//shuan code from memory
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        HashSet<String> set = new HashSet<>();
        set.addAll(wordDict);
        
        int n = s.length();
        // can break [0, i)
        boolean [] dp = new boolean[n+1];
        dp[0] = true;
        //to fill dp 1 to n
        for (int i = 1; i <=n; i++) {
            for (int j = 0; j < i; j++) {
                // [0 -- j -- i)
                String word = s.substring(j,i);
                if (dp[j] && set.contains(word)) {
                    dp[i] = true;
                    break;
                    
                }
            }
            
        }
        return dp[n];  //can break string [0,n)
    }
}
