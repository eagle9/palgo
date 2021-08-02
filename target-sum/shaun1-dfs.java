//shaun own idea and code, tried a testing recursion tree before okay, 
//accepted first sub
//this idea is the brute force by lt
//time is O(2^n), think about the recursion tree, space is O(n)
//runtime 1068ms, faster than 22%, mem less than 81%

class Solution {
    int ans = 0;
    public int findTargetSumWays(int[] nums, int target) {
        int sum = 0;
        helper(nums, 0, sum, target);
        return ans;
    }
    
    //growing candidate sum before reaching pos
    void helper(int [] nums, int pos, int sum, int target) {
        if (pos == nums.length) {
            if (sum == target) ans++;
            return;
        }
        
        helper(nums, pos+1, sum+nums[pos], target);
        helper(nums, pos+1, sum-nums[pos], target);
    }
}

