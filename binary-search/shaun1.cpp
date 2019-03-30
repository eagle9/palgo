//use donglin's bs template, runtime = 52ms, faster than 72%, memory less than 97%
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int n = nums.size();
        int left  = 0, right = n-1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                left = mid+1;
            }else { //target < nums[mid]
                right = mid-1;
            }
        }
        //right left
        // -1    0
        //right left
        // n-1   n
		// left or right not yet compared with target, check the loop
        if (left == 0   && nums[left] == target) return left;
        if (right==n-1  && nums[right] == target) return right;
        return -1;
    }
};
