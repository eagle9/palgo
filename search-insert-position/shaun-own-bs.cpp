/*
shaun own idea, really, first >= target element index observing from the examples
c++ lower_bound or binary search
accepted after 1 bug fixes, final check if you are not clear
first >= target element index, what does this mean? 
if our guess nums[mid] >= target, [left mid right] takes lower half [left, mid]
or right = mid

runtime 8ms, faster than 70%, mem less than 72%
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (target <= nums[mid]) {
                right = mid; //go to lower half
            }else { //target > mid
                left = mid+1;
            }
        }
        //exit left == right 
        //previous iter: left'(mid')+1 == right, target > mid'
        //so nums[right] >= target ----> bug, you can do one more check
        //return right; --- bug
        
        if (nums[right] >= target) return right;
        else return right+1;
    }
};

//grandyang bs template
//runtime 8ms, faster than 99%, mem less than 98%
class Solution1 {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int n = nums.size();
        int left = 0, right = n-1;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] < target)
                left = mid+1;
            else  // nums[mid] >= target, ==  squeeze to left
                right = mid;
        }
        
        if (target < nums[0]) return 0;
        if (nums[n-1] < target) return n;
        
        return left;
        
    }
};

//use lower_bound, runtime 8ms, faster than 99%
class Solution2 {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int n = nums.size();
        //find first it >= target
        auto it = lower_bound(nums.begin(), nums.end(), target);
        return it - nums.begin();
        
        
    }
};



//template donglin 
//runtime 8ms, faster than 99%, mem less than 98%
class Solution3 {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int searchInsert(vector<int> &nums, int target) {
        // write your code here
        if (nums.empty()) return 0;
        
        int left = 0, right = nums.size()-1;
        while (left <=  right) {
            int mid = left + (right - left)/2;
            if (nums[mid] >= target) {// left ---target --- mid
                right = mid-1;
            }
            else { //nums[mid] < target   mid target ... right
                left = mid+1;
            }
        }
		//screeze [] under target, push left to right, or push right to left
        //right left=0
        // right=n-1 left=n
        return left;
        
    }
};
