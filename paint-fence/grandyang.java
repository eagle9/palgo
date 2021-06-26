
public class Solution {
    /**
     * @param n: non-negative integer, n posts
     * @param k: non-negative integer, k colors
     * @return: an integer, the total number of ways
     */
    
        // write your code here
        
        /*
        my init try to get recurrence for DP, not successful
        f(0) = 0
        f(1) = 2
        f(2) = 2*2
        00  01       10         11 
        001 010 011  101 100    110
        f(3)= 2 + 2*2 = 6
        f(4) = 2 + 4*2 = 10
        
        
        
        f(4) = f(3)*(k-1)
        n= 3, k = 2
        f(1) = 2
        f(2) = 2*2 = 4
        f(3) = 
        
        i-1, i same color, 
        same = dp[1], diff = k(k-1)
        dp[3] = f(dp[1], dp[2])
        
        */
   
    //grandyang, not quite understand, understand now. not natural to get it, key point is to classify, and iterate for each group
    //beats 78%
    public int numWays(int n, int k) {
            if (n == 0) {
                return 0;
            } else if (n == 1) {
                return k;
            }
            //n = 2, sameColor: 00 11, diffColor:   01  10
            //n =3,  diffColor: 001 110,  010, 101
            //       sameColor: 011, 100
            int sameColorCnt = k;
            int diffColorCnt = k * (k - 1);
            //n=3, iteratce once, n=4, twice, etc. 
            for (int i = 2; i < n; i++) {
                int temp = diffColorCnt;
                //01  10 ==> 010, 101
                //for each diffColor, *(k-1) ==> diffColor
                //for each sameColor, *(k-1)  ==> diffColor
                //sameColor n <----  diffColor n-1 * 1, use the same color at n-1 position
                diffColorCnt = (diffColorCnt + sameColorCnt) * (k - 1);
                sameColorCnt = temp;
            }
            return sameColorCnt + diffColorCnt;
        }
}
