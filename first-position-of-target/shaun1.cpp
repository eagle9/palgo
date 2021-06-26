//beats 27%
class Solution {
public:
    /**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
    int binarySearch(vector<int> &nums, int target) {
        // write your code here
        if (nums.empty()) return -1;
        
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
        //right |left
        if (nums[left] == target) return left;
        return -1;
    }
};
