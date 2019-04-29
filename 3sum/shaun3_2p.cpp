//shaun from own idea, first sub wrong answer
//right idea direction, slight fix, accepted
//runtime 100ms, faster than 92%, mem less than 98%
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        //int i = 0;
        //while (i < n-2) {
        for (int i = 0; i < n-2; ++i) {
            //nums[i], look for two sum i+1 to n-1
            //if (i >0 && nums[i] == nums[i-1]) continue;
            
            int left = i+1, right = n-1;
            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++; right--;
                    while (left < right && nums[left] == nums[left-1]) left++;
                    while (left < right && nums[right] == nums[right+1]) right--;
                }else if (sum < 0 ) {
                    left++;
                }else {
                    right--;
                }
            }
            while (i < n-2 && nums[i+1] == nums[i]) i++;
            
        }
        return res;
    }
};
