/*
Runtime: 0 ms, faster than 100.00% of Java online submissions for Find First and Last Position of Element in Sorted Array.
Memory Usage: 44.3 MB, less than 26.95% of Java online submissions for Find First and Last Position of Element in Sorted Array.

shaun 3rd try, accepted after 1 bug fix, recalled all details
tricky problem

*/
class Solution {
    public int[] searchRange(int[] nums, int target) {
        
        
        int [] res = {-1,-1};
        if (nums.length ==0) return res;

        int left = 0, right = nums.length-1;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (target <= nums[mid]) { //when == go the left side, to find first
                right = mid;
            }else { // nums[mid] < target, simply go right half
                left = mid+1;
            }
        }
        //left == right now
        if (nums[right] == target) res[0] = right;
        
        left = 0;
        right = nums.length-1;
        while (left+1 < right) {// why this condition, because left =mid, tricky
            int mid = left + (right - left)/2;
            if (target < nums[mid]) { //when == go the left side, to find first
                right = mid;
            }else { // nums[mid] <= target, simply go right half
                left = mid;
            }
        }
        //now left +1 == right
        if (nums[right] == target) res[1] = right;
        else if (nums[left] == target) res[1] = left; //bug add else before if
        return res;
        
    }
}
