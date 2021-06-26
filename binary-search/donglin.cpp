//use donglin's bs template, runtime = 52ms, faster than 72%, memory less than 97%
class Solution1 {
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
        if (left == 0   && nums[left] == target) return left;
        if (right==n-1  && nums[right] == target) return right;
        return -1;
    }
};

//shaun modified donglin template, runtime 52ms, faster than 73%, mem  less than 97%
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int n = nums.size();
        int left  = 0, right = n-1;
        while (left +1 < right) {
            int mid = left + (right - left)/2;
            //if (nums[mid] == target) return mid;
            if (nums[mid] <= target) {
                left = mid;
            }else { //target < nums[mid]
                right = mid-1;
            }
        }
        
        if (nums[left] == target) return left;
        if (nums[right] == target) return right;
        
        return -1;
    }
};
