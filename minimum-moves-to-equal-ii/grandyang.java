/*
grandyang idea1, great idea!
这道题是之前那道Minimum Moves to Equal Array Elements的拓展，现在我们可以每次对任意一个数字加1或者减1，让我们用最少的次数让数组所有值相等。一般来说这种题目是不能用暴力方法算出所有情况，因为OJ一般是不会答应的。那么这道题是否像上面一道题一样，有巧妙的方法呢？答案是肯定的。下面这种解法实际上利用了之前一道题Best Meeting Point的思想，是不感觉很amazing，看似完全不相干的两道题，居然有着某种内部联系。我们首先给数组排序，那么我们最终需要变成的相等的数字就是中间的数，如果数组有奇数个，那么就是最中间的那个数字；如果是偶数个，那么就是中间两个数的区间中的任意一个数字。而两端的数字变成中间的一个数字需要的步数实际上就是两端数字的距离，讲到这里发现是不是就和这道题Best Meeting Point的思路是一样了。那么我们就两对两对的累加它们的差值就可以了，

beats 35%
*/
class Solution {
    public int minMoves2(int[] nums) {
        int res = 0, left = 0, right = nums.length - 1;
        Arrays.sort(nums);
        while (left < right) {
            res += nums[right--] - nums[left++];
        }
        return res;
    }
}
