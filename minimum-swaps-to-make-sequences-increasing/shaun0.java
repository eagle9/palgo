//shaun first try, wrong answer
class Solution0 {
    public int minSwap(int[] A, int[] B) {
        
        int n = A.length; 
        //n > 0 from problem statement
        if (n != B.length || n < 1) return -1;
        
        if (n ==1) return 0; //A and B already strictly increasing
        int [] dp = new int[n];
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            int swap = 0;
            
            if (A[i-1] >= A[i]) {
                
                swap = 1;
            }else if (B[i-1] >= B[i]){
                
                swap = 1;
            }
            if (swap == 1) {
                //two ways to swap A[i-1] B[i-1] or A[i] B[i]
                int temp = A[i-1];
                A[i-1] = B[i-1];
                B[i-1] = temp;
                minSwap(A,B)
            }
            dp[i] = dp[i-1] + swap;
        }
        return dp[n-1];
    }
}
