//shaun idea with prefix sum, brute force iterating all ij
//first sub wrong answer, prefixSum calculation wrong. 
//fixed it, accepted
//runtime 464ms, faster than 5%, mem less than 100%
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefSum(n+1);   //prefSum[i] is sum from 0 to i-1, or sum of first i numbers
        for (int i =1; i <= n; ++i) prefSum[i] = prefSum[i-1]+nums[i-1];
        
        int res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int sum = prefSum[j+1] - prefSum[i];
                if (sum > res) res = sum;
            }
        }
        return res;
    }
};
