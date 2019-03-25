//hua  runtime 20ms, faster than 89%
class Solution1 {
public:
  int findMinDifference(vector<string>& timePoints) {    
    constexpr int kMins = 24 * 60;
    set<int> seen;    
    for (const string& time : timePoints) {
        //hh:mm --> hh* 60 + mm
      int m = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
      //set insert return  std::pair<iterator,bool> 
      if (!seen.insert(m).second) return 0;
    }
    
    int ans = (*seen.begin() - *seen.rbegin() + kMins) % kMins;
    const int* l = nullptr;
    for (const int& t : seen) {
      if (l) ans = min(ans, t - *l);
      l = &t;
    }
    return ans;
  }
};


//grandyang, very easy to read, runtime 24ms, faster than 74%
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int res = INT_MAX, n = timePoints.size();
        vector<int> nums;
        for (string str : timePoints) {
            int h = stoi(str.substr(0, 2)), m = stoi(str.substr(3));
            nums.push_back(h * 60 + m);
        }
        sort(nums.begin(), nums.end()); //i came up sort
        for (int i = 1; i < n; ++i) {
            res = min(res, nums[i] - nums[i - 1]);
        }
        return min(res, 1440 + nums[0] - nums.back()); //deal with circular, +1440
        //draw a pic, will be very clear
    }
};
