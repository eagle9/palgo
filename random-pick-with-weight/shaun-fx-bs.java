/*

idea forming may 2020
0.    1.     2
- | - - - | - -

random number from 0-6, if less 1, return index 0,  
else if r< 4, return 1,
else return 2

idea is in right direction, but to implement, need more specific approaches
accumulate sum is sorted array, find index using binary search, bingo

Runtime: 21 ms, faster than 89.58% of Java online submissions for Random Pick with Weight.

*/
class Solution {
    int [] sum;
    Random rand;
    public Solution(int[] w) {
        
        sum = new int[w.length];
        sum[0] = w[0]; 
        for (int i = 1; i < w.length; ++i) {
            sum[i] = sum[i - 1] + w[i];
        }
        rand = new Random();
    }   
    
    //use binary search to find the first index whose value > target
    //  while num[mid] > target, keep going to lower half: right = mid
    int pickIndex() {
        int target = rand.nextInt(sum[sum.length-1]);
        int left = 0, right = sum.length - 1;
        //first >  
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (sum[mid] <= target) left = mid + 1;
            else right = mid; // sum[mid] > target, first half
        }   
        //left == right
        return right;  //sum[right] > target and be the first
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
