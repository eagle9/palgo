/*
喜刷刷
xss
同样可以用greedy解决。与I不同的是，求的不是对每个i，从A[0:i]能跳到的最远距离；而是计算跳了k次后能达到的最远距离，这里的通项公式为：

d[k] = max(i+A[i])     d[k-2] < i <= d[k-1]

cutting: curMax = max(curMax, nums[i] + i), jump from i, i < lastMax
http://bangbingsyb.blogspot.com/2014/11/leetcode-jump-game-i-ii.html
runtime 12ms, faster than 71%, mem less than 85%
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curMax = 0, njumps = 0, i = 0;
        while(curMax<n-1) {
            int lastMax = curMax;
            for(; i<=lastMax; i++) 
                curMax = max(curMax,i+nums[i]);
            njumps++;
            //no gain jumping forward
            if(lastMax == curMax) return -1;
        }
        return njumps;
    }
};

