//grandyang loop, runtime 95%, mem less than 78%
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 0, cnt = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i == 0 || nums[i - 1] < nums[i]) res = max(res, ++cnt);
            else cnt = 1;
        }
        return res;
    }
};
