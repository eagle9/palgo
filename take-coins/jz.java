public class Solution {
    /**
     * @param list: The coins
     * @param k: The k
     * @return: The answer
     */
     //beats 79.39%, with jz help
    public int takeCoins(int[] list, int k) {
        int n = list.length;
        int [] preSum = new int[n+1]; //preSum[i] store sum from 0 to i-1
        preSum[0] = 0;
        
        for (int i = 1; i <= n; i++) {
            preSum[i] = preSum[i-1] + list[i-1];
        }
        int ans = 0;
        
        //    4,5,6
        //    n-3    n-1,  3 number from right
        // k-3 number from left, it 
        for (int i = 0; i <=k; i++) {
            //take i from right, and k-i from left
            int left = i;  //0, 1, left-1, sum is preSum[left]
            int right = k - i;      //n-1, n-right,  preSum[n] - preSum[n-right]
            int val = preSum[left] + preSum[n] - preSum[n-right];
            if (val > ans) {
                ans = val;
            }
        }
        return ans;
    }
    
    
     //first try only pass 30% test cases, mine is greedy, does not guarantee the max, for example  [5,4,3,100,1] and k = 2, greedy will take 5 and 4, won't take 1 and 100.
     
    public int takeCoins1(int[] list, int k) {
        // Write your code here
        
        //check if k > list.length
        int left = 0, right = list.length-1;
        int value = 0;
        for (int i = 1; i <= k; i++) {
            if (list[left] > list[right]) {
                value += list[left];
                left++;
            }else { //left <= right
                value += list[right];
                right--;
            }
        }
        return value;
    }
}
