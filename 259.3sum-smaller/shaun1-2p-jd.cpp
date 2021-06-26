//jiadai code, shaun has read and understand
//runtime 8ms, faster than 94%, mem less than 63%
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 2) return 0;
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] >= target) {
                    --right;
                }
                else { // i left right < target
                    //i left      right
                    //i left right-1  ===> start+1 to end, how many mumbers end - start-1 + 1 = end -start
                    count += right - left;
                    ++left; //try next left
                }
            }
        }
        return count;
    }
};
