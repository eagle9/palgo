/*
huahua use BST
Runtime: 68 ms, faster than 100.00% of C++ online submissions for Sliding Window Median.
Memory Usage: 15.5 MB, less than 75.38% of C++ online submissions for Sliding Window Median.
*/
class Solution {
public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {    
    vector<double> ans;
    if (k == 0) return ans;
    multiset<int> window(nums.begin(), nums.begin() + k);
    auto mid = next(window.begin(), (k - 1) / 2);    
    for (int i = k; i <= nums.size(); ++i) {
      ans.push_back((static_cast<double>(*mid) + 
                     *next(mid, (k + 1) % 2)) / 2.0);
      if (i == nums.size()) break;
      
      window.insert(nums[i]);
      if (nums[i] < *mid) --mid; 
      if (nums[i - k] <= *mid) ++mid;
      window.erase(window.lower_bound(nums[i - k])); 
    }
    return ans;
  }
};
