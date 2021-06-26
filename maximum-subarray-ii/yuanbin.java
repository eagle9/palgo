//yuanbin, beats 90.40%
//shaun, beats 81.20%
public class Solution {
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    public int maxTwoSubArrays(ArrayList<Integer> nums) {
        // -1 is not proper for illegal input
        if (nums == null || nums.isEmpty()) return -1;

        int n = nums.size();
        // get max sub array forward
        int[] maxSubArrayF = new int[n];
        forward(nums, maxSubArrayF);
        // get max sub array backward
        int[] maxSubArrayB = new int[n];
        backward(nums, maxSubArrayB);
        // get maximum subarray by iteration
        int maxTwoSub = Integer.MIN_VALUE;
        //0 ... i i+1 ... n-1
        //split: 0 to i,   i+1 to n-1, so the end is i < n-1
        for (int i = 0; i < n - 1; i++) {
            // non-overlapping
            maxTwoSub = Math.max(maxTwoSub, maxSubArrayF[i] + maxSubArrayB[i + 1]);
        }

        return maxTwoSub;
    }

    //shuan modified from maximum subarray solution
    //dp idea, to work out an array for values
    private void forward(List<Integer> nums, int [] maxSubArray) {
        int sum = 0;
        int maxSum = Integer.MIN_VALUE;
        int n  = nums.size();
        for (int i = 0; i <= n-1; ++i) {
            if (sum < 0)  //this is key to reset sum
                sum = nums.get(i);
            else
                sum += nums.get(i);
            maxSum =maxSum> sum? maxSum: sum;
            maxSubArray[i] = maxSum;
        }
    }
    //shaun
    private void backward(List<Integer> nums, int [] maxSubArray) {
        int sum = 0;
        int maxSum = Integer.MIN_VALUE;
        int n  = nums.size();
        for (int i = n-1; i >=0; --i) {
            if (sum < 0)  //this is key to reset sum
                sum = nums.get(i);
            else
                sum += nums.get(i);
            maxSum =maxSum> sum? maxSum: sum;
            maxSubArray[i] = maxSum;
        }
    }
    
    //yuanbin's
    private void forwardTraversal(List<Integer> nums, int[] maxSubArray) {
        int sum = 0, minSum = 0, maxSub = Integer.MIN_VALUE;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            minSum = Math.min(minSum, sum);
            sum += nums.get(i);
            maxSub = Math.max(maxSub, sum - minSum);
            maxSubArray[i] = maxSub;
        }
    }

    //yuanbin's
    private void backwardTraversal(List<Integer> nums, int[] maxSubArray) {
        int sum = 0, minSum = 0, maxSub = Integer.MIN_VALUE;
        int size = nums.size();
        for (int i = size - 1; i >= 0; i--) {
            minSum = Math.min(minSum, sum);
            sum += nums.get(i);
            maxSub = Math.max(maxSub, sum - minSum);
            maxSubArray[i] = maxSub;
        }
    }
}
