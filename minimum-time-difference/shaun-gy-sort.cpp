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
