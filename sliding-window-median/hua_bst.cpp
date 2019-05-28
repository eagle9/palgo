/*
huahua use BST, confusing, not clear
Runtime: 68 ms, faster than 100.00% of C++ online submissions for Sliding Window Median.
Memory Usage: 15.5 MB, less than 75.38% of C++ online submissions for Sliding Window Median.
*/
class Solution {
public:
  vector<double> medianSlidingWindow(vector<int>& nums, int k) {    
    vector<double> ans;
    if (k == 0) return ans;
    multiset<int> window(nums.begin(), nums.begin() + k);
	//k = 3, idx: 0,1,2, median idx =1 
	//k = 4, idx: 0,1,2,3, median idx = 1, so mid = (k-1)/2
    auto mid = next(window.begin(), (k - 1) / 2);    
    for (int i = k; i <= nums.size(); ++i) {
	  //mid odd, mid      (k+1)%2 = 0
	  //mid even mid+1    (k+1)%2  = 1
      ans.push_back((static_cast<double>(*mid) + 
                     *next(mid, (k + 1) % 2)) / 2.0);
      if (i == nums.size()) break;
      
      window.insert(nums[i]);
	  //insert 
	  // mid=3, 1 mid 4 5 --> 1 2 mid 4 5  ==> mid-- why?
	  // mid=3, 1 2 mid 4 5 --> 1 2 2 mid 4 5 ==> mid--  yes 
      if (nums[i] < *mid) --mid; 
	  // remove before mid val = 3
	  // 1 mid 4 5 --> mid 4 5 ==> mid++  yes
	  // 1 2 mid 4 5  -->2 mid 4 5  ==> mid++  why???
      if (nums[i - k] <= *mid) ++mid;
	  //lower_bound first it >= val
      window.erase(window.lower_bound(nums[i - k])); 
    }
    return ans;
  }
};
