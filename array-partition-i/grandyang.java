//grandyang idea, very good, shaun java code
/*
这道题让我们分割数组，两两一对，让每对中较小的数的和最大。这题难度不大，用贪婪算法就可以了。由于我们要最大化每对中的较小值之和，那么肯定是每对中两个数字大小越接近越好，因为如果差距过大，而我们只取较小的数字，那么大数字就浪费掉了。明白了这一点，我们只需要给数组排个序，然后按顺序的每两个就是一对，我们取出每对中的第一个数即为较小值累加起来即可，
*/
//beats 20%
class Solution {
    
    public int arrayPairSum(int[] nums) {
        int res = 0, n = nums.length;
        Arrays.sort(nums);
        for (int i = 0; i < n; i += 2) {
            res += nums[i];
        }
        return res;
    }
}
