//jiadai c++, Your submission beats 91.60% Submissions!
//shaun write in java, modified it into a DP, Your submission beats 95.60% Submissions!
public class Solution{
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    public int fibonacci(int n) {
        // write your code here
        if (n == 1) return 0;
        if (n == 2) return 1;
        int [] fibo = new int[n+1];
        fibo[1] = 0;
        fibo[2] = 1;
        for (int i = 3; i <= n; ++i)        {
            fibo[i] = fibo[i-1] +  fibo[i-2];
        }

        return fibo[n];
    }
};
