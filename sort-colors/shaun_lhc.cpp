//linhuchong 3 pointer idea, shaun from memory of the idea
//accepted after 1 fix, work out with a couple of examples
//shaun original idea kind of having the direction, but not sharp enough
//runtime 4ms, faster than 100%, mem less than 9%
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        int i = 0;
        while (i <= right) {
            if (nums[i] == 2) {
                swap(nums[i], nums[right]);
                right--;
                continue;
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[left]);
                left++;
                i++;
                continue;
            }
            i++;
        }
    }
};
