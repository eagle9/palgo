//shaun idea, first sub wrong answer,
//one small fix, accepted
//runtime 40ms, faster than 66%, mem less than 100%
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n-3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n-2; ++j) {
                //if (j >0 && nums[j] == nums[j-1]) continue; ==> wrong answer, j starts from i+1, not 0
                if (j >i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1, right = n-1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++; right--;
                        while (left < right && nums[left] == nums[left-1]) left++;
                        while (left < right && nums[right] == nums[right+1]) right--;
                    }else if (sum < target) left++;
                    else right--;
                }
            }
        }
        return res;
    }
};
