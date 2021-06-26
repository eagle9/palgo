//jiadai c++ --> java Your submission beats 99.60% Submissions!
public class Solution{
    /*
     * @param nums: An array of integers
     * @return: An array of integers that's next permuation
    */
    public int[] nextPermutation(int [] nums) {
        // write your code here
        int n = nums.length;
        if (n == 0 || n == 1)
            return nums;

        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0) {
            int j = n - 1;
            while (j > i && nums[j] <= nums[i])
                j--;
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }

        i = i+1;
        int j = n-1;
        while (i < j) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
            j--;
        }
        return nums;
    }
}
