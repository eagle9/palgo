//grandyang dp, beats 97%
//dp bottom up tabular, 
public class Solution {

    public int rotatedDigits(int N) {
        int res = 0;
        int [] dp = new int[N + 1]; //java default value 0
        for (int i = 0; i <= N; ++i) {
            if (i < 10) {
                if (i == 0 || i == 1 || i == 8) dp[i] = 1;
                else if (i == 2 || i == 5 || i == 6 || i == 9) {
                    dp[i] = 2; 
                    ++res;
                }
            //i >= 10    
            } else {
                //work on the recurrence
                int a = dp[i / 10], b = dp[i % 10];
                
                //rotate to itself
                if (a == 1 && b == 1) dp[i] = 1;
                //either a or b is 2 and the other is 1 or 2
                //that means rotates into another number
                else if (a >= 1 && b >= 1) {
                    dp[i] = 2; 
                    ++res;
                }
                
                //now a = 0 or b== 0
                //no update to dp[i], stay 0
            }
        }
        return res;
    }
};
