//shaun own idea and code, tried a testing recursion tree before okay, 
//accepted first sub
//this idea is the brute force by lt
//time is O(2^n), think about the recursion tree, space is O(n)
//runtime 1068ms, faster than 22%, mem less than 81%
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int ans = 0, sum = 0;
        helper(nums, 0, sum, S, ans);
        return ans;
    }
    
private:
    //growing candidate sum before reaching pos
    void helper(vector<int>& nums, int pos, int sum, int target, int& ans) {
        if (pos == nums.size()) {
            if (sum == target) ans++;
            return;
        }
        
        helper(nums, pos+1, sum+nums[pos], target, ans);
        helper(nums, pos+1, sum-nums[pos], target, ans);
    }
};


