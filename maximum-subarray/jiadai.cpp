//jiadai c++, Your submission beats 99.20% Submissions!
class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
        // write your code here
        int sum = nums[0];
        int maxSum = nums[0];
        int n  = nums.size();
        for (int i = 1; i < n; ++i) {
            if (sum < 0)  //this is key to reset sum
                sum = nums[i];
            
            else 
                sum += nums[i];
            
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};
