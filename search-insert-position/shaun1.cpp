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
class Solution {
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
class Solution2 {
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
