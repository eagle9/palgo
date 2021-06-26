//grandyang idea 2, 0ms, faster than 100%
//not fully understand
//found https://www.jianshu.com/p/ded42b5418c7
//runtime 0ms, faster than 100%, memory less than 21%
class Solution {
    public int singleNonDuplicate(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1])
                return nums[mid];
            
            if ((mid % 2 ==0 && nums[mid] == nums[mid+1]) || 
                (mid % 2 ==1 && nums[mid] == nums[mid-1]) ){
                //even numbers befoe mid, single in right half, contract left
                left = mid+1;
            }else { //in left half, contract right
                right = mid-1;
            }
            
        }
        //left == right now
        return nums[left];
    }
}
//shaun's nervous first try, 
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
