//i liked hua's dp idea and coded from understanding of the idea
//cutting:
//init from 1 group, elements from 0 to n-1
//consider i groups of elements from 0 to j
//  can we use i-1 groups result? split 0 ..k .. j
// .  0 to k i-1 groups ---> min sum is dp[i-1][k], k+1 to j 1 group whose sum is psum[j]- psum[k], for this case, the min sum is min(dp[i-1][k], psum[j] - psum[k])
// accepted after fixing signed integer overflow
//runtime 136ms, faster than 26%, mem less than 30%
// time is O(m*n^2)
class Solution {
public:
    //split array nums into m groups(continuous non-empty subarrays) such that the largest sum is minimized, kind of the most fair partition
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        //dp[i][j] minimized sum for m groups for nums 0 to j
        //init with max, we want to minimize
        vector<vector<long>> dp(m+1, vector<long>(n, INT_MAX));
        
        long sum = 0;
        vector<long> psum(n);
        for (int j = 0; j < n; ++j) {
            sum += nums[j];
            psum[j] = sum;
        }
        //initialize 1 group
        for (int j = 0; j < n; ++j)
            dp[1][j] =  psum[j]; //sum from 0 to j
        
        for (int i = 1; i <= m; ++i) {  //i groups parition
            for (int j = i-1; j < n; ++j) {             //number of elements = j at least >= i, last  otherwise can not partition into m groups, last index j-1, len = j
                //0 1 ..k .. j
                for (int k = 0; k < j; ++k) {
                    //split at k, 0-k elements i-1 groups, k+1 to j 1 group
                    sum = max(dp[i-1][k], psum[j] - psum[k]);
                    dp[i][j] = min(dp[i][j], sum);
                }
            }
        }
        return (int)dp[m][n-1]; //m groups for elements from 0 to n-1
    }
};
