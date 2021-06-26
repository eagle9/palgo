//shaun code from hua's divide and conquer idea
//runtime 8ms, faster than 99%, mem less than 60%
class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
private:
    int helper(vector<int>& nums, int left, int right) {
        if (left+1 >= right) return min(nums[left], nums[right]);
        //sorted
        if (nums[left] < nums[right]) return nums[left];
        int mid = left + (right - left)/2;
        return min(helper(nums,left,mid), helper(nums,mid+1, right));
    }
};
