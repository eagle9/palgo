/*
grandyang1,  O(n)

Runtime: 12 ms, faster than 98.45% of C++ online submissions for Maximum Subarray.
Memory Usage: 10.3 MB, less than 78.19% of C++ online submissions for Maximum Subarray.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN, curSum = 0;
        for (int num : nums) {
            curSum = max(curSum + num, num);
            res = max(res, curSum);
        }
        return res;
    }
};
