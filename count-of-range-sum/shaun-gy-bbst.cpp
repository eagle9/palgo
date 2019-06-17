/*
shaun read and understand grandyang sort with balanced search tree

Runtime: 40 ms, faster than 89.36% of C++ online submissions for Count of Range Sum.
Memory Usage: 12.3 MB, less than 66.67% of C++ online submissions for Count of Range Sum.

*/
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int res = 0;
        long long sum = 0;
        //balanced bst 
        multiset<long long> sums;
        sums.insert(0);
        //range sum in [lower, upper]
        
        // sum[i] - upper <= sum[j]   <= sum[i] - lower
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            //first sum1 >= sum - upper
            //or first sum - sum1 <= upper
            auto it1 = sums.lower_bound(sum - upper);
            //first sum1 > sum - lower
            //or sum - sum1 < lower
            // go back 1  sum11 <= sum - lower
            // .    sum - sum11 >= lower
            auto it2 = sums.upper_bound(sum - lower);
            
            res += distance(it1, it2);
            
            sums.insert(sum);
        }
        return res;
    }        
};
