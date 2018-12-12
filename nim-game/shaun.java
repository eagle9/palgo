public class Solution {
    /**
     * @param n: an integer
     * @return: whether you can win the game given the number of stones in the heap
     */
     
     //recursive call, 44% test cases passed, TLE
    public boolean canWinNim0(int n) {
        // Write your code here
        
        if (n == 1 || n == 2 || n == 3)
            return true;
        if (n == 4)
            return false;
        
        //i take 1,2, 3, he always win, then i lose
        if (canWinNim(n-1) && canWinNim(n-2) && canWinNim(n-3))
            return false;
        else //at lease one way for him to lose, i win
            return true;
        
    }
    ///MLE -- memory limit exceeded
    public boolean canWinNim2(int n) {
        // Write your code here
        boolean [] dp = new boolean[n+1];
        if (n == 1 || n == 2 || n == 3)
            return true;
        
        dp[1] = true; 
        dp[2] = true;
        dp[3] = true;
        dp[4] = false;
        
        for (int i = 5; i <= n; i++) {
            //i take 1,2, 3, he always win, then i lose
            if (dp[i-1] && dp[i-2] && dp[i-3])
                dp[i] = false;
            else //at lease one way for him to lose, i win
                dp[i] = true;
        }
        return dp[n];
        
    }
    
    //beats 61%, find the rule from recursive call, beats 100%
    public boolean canWinNim(int n) {
        return n%4 == 0? false: true;
    }
    /*
    testing:
    n = 1   true
    n = 2   true
    n= 3, true
    n= 4, false
    n= 5, true 5-1 = 4
    n = 6, true, 6-2 = 4, i can make him lose
    n = 7, true, 7-3 = 4, i can make him lose too
    n = 8, 5-6-7 all win, no way for him to lose, he always wins, i lose
    */
}
