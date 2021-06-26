/*

grandyang idea, bit by bit, figure out distance at ith bit
shaun read and understand
Runtime: 60 ms, faster than 96.67% of C++ online submissions for Total Hamming Distance.
Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Total Hamming Distance.
*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0, n = nums.size();
        for (int i = 0; i < 32; ++i) {
            int ones = 0;
            for (int num : nums) {
                if (num & (1 << i)) ++ones;
            }
            res += ones * (n - ones); //#number of 1s * number of 0s
        }
        return res;
    }
};
