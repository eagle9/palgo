//grandyang idea 2, 0ms, faster than 100%
//not fully understand
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int buddy = (mid % 2 == 0)? mid+1: mid-1;
            //int buddy = mid ^ 1;
            // odd-1 == odd 
            if (nums[mid] == nums[buddy]) left = mid + 1;
            else right = mid;
        }
        return nums[left];
    }
}
//index out of bound, then wrong answer
class Solution2 {
    public int singleNonDuplicate(int[] nums) {
        //break the array into to arrays
        //nums.length must be odd
        int left = 0, right = nums.length-1;
        while (left+1 < right) {
            int mid = left + (right-left)/2;
            //0 -- mid,   mid+1 -- right

            //first array length = mid - left +1
            if ((mid - left+1) % 2 ==1) {

                if (nums[mid] == nums[mid+1]) left = mid;
                else if (nums[mid] == nums[mid-1]) right = mid;
                else return nums[mid];
            }else { //first array length even
                if (nums[mid] == nums[mid-1]) left = mid;
                else if (nums[mid] == nums[mid+1]) right = mid;
                
                
            }
        }
        //now left > right
        return nums[left];
    }
}
