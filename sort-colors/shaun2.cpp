//shaun learned idea(first time know two storing indexes, but not quite getting the point)
//second round first sub wrong answer, quickly fixed and accepted. remember use a 1 test case to figure out the details
//runtime 4ms, faster than 100%, mem less than 22%
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i0 = 0, i2 = n-1, i = 0;
        while (i <= i2) {
            if (nums[i] == 0) {
                swap(nums[i], nums[i0]);
                i0++;
                i++;
            }else if (nums[i] == 2) {
                swap(nums[i], nums[i2]);
                i2--;
            }else {
                i++;
            }
        }
    }
};
