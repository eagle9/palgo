/*
grandyang binary search
Runtime: 104 ms, faster than 87.50% of C++ online submissions for Maximum Average Subarray II.
Memory Usage: 12.7 MB, less than 100.00% of C++ online submissions for Maximum Average Subarray II.

*/
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double left = *min_element(nums.begin(), nums.end());
        double right = *max_element(nums.begin(), nums.end());
        while (right - left > 1e-5) {
            double minSum = 0, sum = 0, preSum = 0, mid = left + (right - left) / 2;
            bool check = false;
            for (int i = 0; i < nums.size(); ++i) {
                sum += nums[i] - mid;
                if (i >= k) {
                    preSum += nums[i - k] - mid;
                    minSum = min(minSum, preSum);
                }
                if (i >= k - 1 && sum > minSum) {check = true; break;}
            }
            if (check) left = mid;
            else right = mid;
        }
        return left;
    }
};
