/* Author: Huahua
 Runtime: 52 ms, faster than 63.01% of C++ online submissions for Subarray Sum Equals K.
Memory Usage: 18.1 MB, less than 100.00% of C++ online submissions for Subarray Sum Equals K.
Running Prefix sum


*/
class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    if (nums.empty()) return 0;
    unordered_map<int, int> counts{{0,1}};
    int cur_sum = 0;
    int ans = 0;
    for (const int num : nums) {
      cur_sum += num;      
      ans += counts[cur_sum - k];
      ++counts[cur_sum];
    }
    return ans;
  }
};

