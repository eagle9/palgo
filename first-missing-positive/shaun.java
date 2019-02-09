//idea https://www.jianshu.com/p/9cfe8c7353b3
//shaun java code from the idea in memory
//runtime 5ms, faster than 99%, memory less than 14%
//time O(n), space O(n), not meeting the problem requirements
//this one helps to understand the problem requirements
class Solution1 {
    public int firstMissingPositive(int[] nums) {
        if (nums.length == 0) return 1;
        
        boolean [] flag = new boolean[nums.length+1];
        for (int i: nums) {
            if (i > 0 && i <= nums.length)
                flag[i] = true;
        }
        for (int i = 1; i <= nums.length; i++) {
            if (!flag[i]) return i;
        }
        return nums.length+1;
    }
}

//grandyang idea2, if nums[i] in range from 1 to n,  great idea!!!! tricky to have a while loop inside for loop, but it is so powerful
//nums[i] = v, find nums[ v - 1] == nums[i]??? 
//  1 to 0
//  2 to 1
// how about nums[i] that are out of range 1 to n? don't care

//go through the array nums, if we can not find nums[i] = i +1, return nums
//runtime 5ms, faster than 99%, memory less than 13%, Feb 8 2019
class Solution {
    public int firstMissingPositive(int [] nums) {
        if (nums.length == 0) return 1;
        for (int i = 0; i < nums.length; i++) {
            int v = nums[i];
            //key to use the while loop, not just one single swap, you have to take care of the new nums[i] after swap
            while (1 <= nums[i] && nums[i] <= nums.length && nums[ nums[i] -1] != nums[i]) {
                    int temp = nums[nums[i]-1];
                    nums[nums[i]-1] = nums[i];
                    nums[i] = temp;
                
            }
        }
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != i+1) return i+1;
        }
        return nums.length+1;
    }
}

