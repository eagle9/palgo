/*
Runtime: 16 ms, faster than 42.61% of C++ online submissions for Jump Game.
Memory Usage: 10.5 MB, less than 100.00% of C++ online submissions for Jump Game.

grandyang dp, O(n) time, not easy to come up through
*/
class Solution1 {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        //dp[i]表示达到i位置时剩余的步数
        vector<int> dp(n,0);
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i-1],nums[i-1])-1;
            if (dp[i] < 0) return false;
            
        }
        return true;
    }
};
/*
grandyang greedy
Runtime: 12 ms, faster than 98.84% of C++ online submissions for Jump Game.
Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Jump Game.
reach 表示最远能到达的位置，初始化为0。遍历数组中每一个数字，如果当前坐标大于reach或者reach已经抵达最后一个位置则跳出循环，否则就更新reach的值为其和i + nums[i]中的较大值，其中i + nums[i]表示当前位置能到达的最大位置
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), reach = 0;
        for (int i = 0; i < n; ++i) {
            if (i > reach || reach >= n - 1) break;
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;
    }
};
