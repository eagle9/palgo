//shaun raw idea, but details checked with grandyang code
//you have to come up with longer permutations to find the rule
// 1 3 2 -> 2 1 3
// 1 2 7 4 3 2 1 ---- find a1 = 2 the first down number from right to left, i = 1
// 1 3 7 4 2 2 1 ---- find 3 > 2,  
// 1 3 [7 4 2 2 1]  swap 2 3
// 1 3 [1 2 2 4 7]  reverse [] to make it smaller
//Runtime: 0 ms, faster than 100.00% of Java online submissions for Next Permutation.
class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;
        int i = n - 2;
        //1 3 2
        //2 3 1
        //go from right to left, up slope, keep going, find first down number, candiate to ++
        while (i >=0 && nums[i] >= nums[i+1]) --i;
        //now i < 0 or nums[i] < nums[i+1]
        if (i >=0) {
            //go from right to left, find the first number nums[j] > nums[i]
            int j = n-1;
            while (nums[j] <= nums[i]) --j;
            //nums[j] > nums[i]
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        i++;
        int j = n-1;
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
    }
}

