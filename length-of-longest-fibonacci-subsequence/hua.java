/*

// huahua idea, shaun java code, 
// Running time: 65 ms, beats 84%
//
// w/ Hashtable
// Time complexity: O(n^2)
// Space complexity: O(n^2)

*/
class Solution {
    public int lenLongestFibSubseq(int[] A) {
        int n = A.length;        
        Map<Integer, Integer> m = new HashMap<>(); // key Ai val is i
        for (int i = 0; i < n; ++i)
            m.put(A[i],i);
        
        int [] [] dp = new int[n][n];  //fib seq len from i to j
        for (int i = 0; i < n; i++) {
            //shaun modified j start from i+1
            for (int j= i+1; j < n; j++) {
                dp[i][j] = 2; //init with 2, naturally since fib seq starts with any two number
            }
        }
        
        int ans = 0;
        //shaun modified to start j from 1
        for (int j = 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                int Ai = A[k] - A[j];
                if (Ai >= A[j]) break; // pruning 168 ms -> 68 ms, fib seq is increasing
            
                if (m.containsKey(Ai)) {
                    int i = m.get(Ai);  //Ai is actually inside A, Ak can be use to expand fib seq
                    dp[j][k] = dp[i][j] + 1;        
                    ans = Math.max(ans, dp[j][k]);
                }
            }
        }
        return ans;
    }
}
/*
kind of enumeration solution
huahua c++, shaun java, 100ms, beats 48%
Time complexity: O(n^3)

Space complexity: O(n)
*/
class Solution2 {
    public int lenLongestFibSubseq(int[] A) {
        int n = A.length;
        Set<Integer> set = new HashSet<>();      
        for (int i = 0; i < n; i++) {
            set.add(A[i]);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = A[i];
                int b = A[j];
                int c = a + b;
                int len = 2;
                while (set.contains(c)) {
                    len++;
                    ans = Math.max(ans, len);
                    //a b c -->
                    //  a b  c
                    a = b;
                    b = c;
                    c = a + b; //for next iteration
                    
                }
            }
        }
        return ans;
    }
}
