/*

注意题目中A[i]表示的是在位置i，“最大”的跳跃距离，而并不是指在位置i只能跳A[i]的距离。所以当跳到位置i后，能达到的最大的距离至少是i+A[i]。用greedy来解，记录一个当前能达到的最远距离maxIndex：

1. 能跳到位置i的条件：i<=maxIndex。
2. 一旦跳到i，则maxIndex = max(maxIndex, i+A[i])。
3. 能跳到最后一个位置n-1的条件是：maxIndex >= n-1
http://bangbingsyb.blogspot.com/2014/11/leetcode-jump-game-i-ii.html
greedy
run
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int maxIndex = 0, n = nums.size();
        for(int i=0; i<n; i++) {
            //if out of reach or reached
            if(i > maxIndex || maxIndex>=(n-1)) break;
            
            maxIndex = max(maxIndex, i+nums[i]);
        } 
        return maxIndex>=(n-1);
    }
};
