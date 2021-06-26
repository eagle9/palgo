//shaun original idea, lintcode two sum cloest helps, similar idea and template
//accepted first sub, runtime 12ms, faster than 64%, mem less than 98%
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int minDiff = INT_MAX, res = 0;
        for (int i = 0; i < n-2; ++i) {
            int left = i+1, right = n-1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    if (target - sum < minDiff) {
                        minDiff = target - sum;
                        res = sum;
                    }
                    left++;
                }else { //sum >= target
                    if (sum - target < minDiff) {
                        minDiff = sum - target;
                        res = sum;
                    }
                    right--;
                }
            }
        }
        return res;
    }
};
