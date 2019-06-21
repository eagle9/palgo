/*
hua sort and two pointers
updated with edward idea

Runtime: 108 ms, faster than 99.94% of C++ online submissions for 3Sum.
Memory Usage: 16.3 MB, less than 89.18% of C++ online submissions for 3Sum.

*/
class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    const int n = nums.size();
      //nums[i] and two numbers after it that sums to 0
    for (int i = 0; i < n - 2; ++i) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      int low = i + 1;
      int high = n - 1;
      int sum = 0 - nums[i];
      while (low < high) {
        if (nums[low] + nums[high] == sum) {
            ans.push_back({nums[i], nums[low++], nums[high--]});
            while (low < high && nums[low] == nums[low - 1]) ++low;
            while (low < high && nums[high] == nums[high + 1]) --high;          
        } else if (nums[low] + nums[high] < sum) {
            ++low;
        } else {
            --high;
        }
      }
    }
    return ans;
  }
};
