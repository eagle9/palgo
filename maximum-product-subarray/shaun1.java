//shaun's own first try, wrong answer, good that coming up with two dp array
//wrong answer
class Solution1 {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int [] dp = new int[n]; //max product suarray from 0 to i
        int [] B = new int[n]; //product subarray ending at i
        B[0] = nums[0];
        dp[0] = nums[0];
        
        for (int i = 1; i < n; i++) {
            B[i] = B[i-1] * nums[i];
            dp[i] = Math.max( dp[i-1],  B[i]);
        }
        
        return dp[n-1];
    }
}

//shaun own java code from grandyang dp idea
//Runtime: 2 ms, faster than 73.88% of Java online submissions for Maximum Product Subarray.
class Solution2 {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int [] max = new int[n];
        int [] min = new int[n];
        max[0] = nums[0];
        min[0] = nums[0];
        
        int res = max[0]; //Integer.MIN_VALUE does not work
        for (int i = 1; i < n; i++) {
            //min can generate max because of negative number
            max[i] =  Math.max( Math.max( max[i-1]* nums[i], min[i-1]*nums[i]), nums[i]);
            min[i] =  Math.min( Math.min( max[i-1]* nums[i], min[i-1]*nums[i]), nums[i]);
            res = Math.max(res, max[i]);
        }
        return res;
    }
}
//reduce dimension because maxi depends only on max i-1
//Runtime: 1 ms, faster than 99.25% of Java online submissions for Maximum Product Subarray.
class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        
        int max = nums[0];
        int min = nums[0];
        
        int res = max; //Integer.MIN_VALUE does not work
        for (int i = 1; i < n; i++) {
            //min can generate max because of negative number
            int max1 =  Math.max( Math.max( max* nums[i], min*nums[i]), nums[i]);
            int min1 =  Math.min( Math.min( max* nums[i], min*nums[i]), nums[i]);
            res = Math.max(res, max1);
            max = max1;
            min = min1;
        }
        return res;
    }
}

