//try idea and code in I, wrong answer
//worst case O(n), but if there are not many duplicated numbers, close to Log(n)
//wrong answer [1,3,1,1,1]
//3
//key direction of thinking: when nums[mid] == nums[left] == num[right], no range to contain target
//checked with grandyang code
//runtime 8ms, faster than 100%, mem less than 93%
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) return false;
        int n  = nums.size();
        int left = 0, right = n-1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
           
            
            if (nums[mid] == target) return true;
            //where is mid?
            if (nums[mid] > nums[left]) { // left mid max
                if (nums[left] <= target && target < nums[mid]) right = mid;
                else left = mid;
            }else if (nums[mid] < nums[left]) { // min   mid right
                if (nums[mid] < target && target <= nums[right]) left = mid;
                else right = mid;
            } else { // nums[mid] == nums[left]
                left++;
            }
        }
        if (nums[left] == target) return true;
        if (nums[right] == target) return true;
        return false;
    }
};

//can not use binary search anymore, runtime 8ms, faster than 100%
//  for instance worst case,  find 0 in 11111111111111111, 
class Solution1 {
public:
    bool search(vector<int>& nums, int target) {
        for (const int i: nums) {
            if (i == target) return true;
        }
        return false;
    }
};
