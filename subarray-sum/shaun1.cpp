//shaun's own idea and code, accepted after drawing and correcting details
//idea of using prefixSum
//beats 79.60%
class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> subarraySum(vector<int> &nums) {
       
        int n = nums.size();
        vector<int> prefixSum (n+1);
        for (int i = 1; i <= n; ++i) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        // prefixSum[i]   sum from 0 to i-1
        //   0 -- i-1  =============prefixSum[i]
        // 0 ----     i  j  ===========prefixSum[j+1]
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                //sum from i to j
                int sum = prefixSum[j+1] - prefixSum[i];
                if (sum == 0) return {i,j};
            }
        }
        //return {};
    }
};
