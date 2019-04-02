//jz and shaun template, runtime 52ms, faster than 74%, mem less than 98%
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size()-1;
        while (left+1 < right) {
            int mid = left + (right-left)/2;
            if (target < nums[mid]) right = mid-1;
            else if (nums[mid] < target) left = mid+1;
            else right = mid;//left = mid;   // == case, left = mid or right = mid all okay
        }
        
        //exit: left right next to each other and in bound
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        return -1;
    }
};
