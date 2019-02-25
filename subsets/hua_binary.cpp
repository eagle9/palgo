/*
huahua binary
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Subsets.
Memory Usage: 9.4 MB, less than 32.72% of C++ online submissions for Subsets.
*/
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> ans;    
    for (int s = 0; s < 1 << n; ++s) {
      vector<int> cur;
      for (int i = 0; i < n; ++i)
        if (s & (1 << i)) cur.push_back(nums[i]);
      ans.push_back(cur);
    }
    return ans;
  }
};
