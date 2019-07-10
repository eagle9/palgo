//shaun first try, wrong answer, changed code, still wrong ans
class Solution0 {
    public int threeSumMulti(int[] A, int target) {
        Arrays.sort(A);
        int n = A.length;
        int res = 0;
        for (int i = 0; i < n-2; i++) {
            int sum = target - A[i];
            int left = i+1, right = n-1;
            while (left < right) {
                if (A[left++] + A[right--] == sum) {
                    res++;
                    while (A[left] == A[left-1] && left < right) {
                        res++;
                        left++;
                    }
                    while (A[right] == A[right+1] && left < right) {
                        res++;
                        right--;
                    }
                }else if (A[left] + A[right] < sum) {
                    left++;
                }else {
                    right--;
                }
            }
        }
        return res;
    }
}
//shaun brute force, wrong answer, not related to original 3sum problem
class Solution {
    public int threeSumMulti(int[] A, int target) {
        Arrays.sort(A);
        int n = A.length;
        long res = 0;
        for (int i = 0; i < n-2; i++) {
            for (int j = i+1; j < n-1; j++) {
                for (int k = j+1; k < n; k++) {
                    if (A[i] + A[j] + A[k] == target)
                        res++;
                }
            }
        }
        int MOD =  (int)1e9 + 7; //10^9 + 7; wrong, ^ is not power, but bit ops
        return (int)res % MOD;
    }
}
//huahua idea, shaun java code, tricky with data types
/*
Runtime: 4 ms, faster than 100.00% of Java online submissions for 3Sum With Multiplicity.
Memory Usage: 38.6 MB, less than 82.35% of Java online submissions for 3Sum With Multiplicity.

*/
class Solution3 {
    public int threeSumMulti(int[] A, int target) {
        //A[i] integer from 0 to 100
        long [] count = new long[101]; // int [] count = new int [101] not working
        for (int i : A)  count[i]++;
        
        long res = 0;
        //3 number <= target, i <= j <= k
        for (int i = 0; i <= target; i++) {
            for (int j = i; j <= target; j++) {
                int k = target - i - j;
                //k in range 0 to 100 and k >= j, invalid k -- skip
                if (k < 0 || k > 100 || k < j) continue; 
                //i j k any of them is not found in count, skip
                if (count[i] == 0 || count[j] == 0 || count[k] == 0) continue;
                if (i == j && j == k) {
                    res +=  count[i] * (count[i] - 1) * (count[i] - 2)/6;   //C(count[i],3)
                }else if (i == j && j != k) {
                    res += count[i]*(count[i]-1)/2 * count[k];
                }else if (i != j && j == k) {
                    res += count[i] * count[j] * (count[j]-1)/2;
                }else {
                    res += count[i] * count[j] * count[k];
                }
                
            }
        }
        //int MOD = 1_000_000_007;
        int MOD = (int)1e9 + 7;  //10^9 not working, it is bit operation 
        return (int) (res % MOD);
        
    }
}
