/*
xss
同样可以用greedy解决。与I不同的是，求的不是对每个i，从A[0:i]能跳到的最远距离；而是计算跳了k次后能达到的最远距离，这里的通项公式为：

d[k] = max(i+A[i])     d[k-2] < i <= d[k-1]
*/

class Solution1 {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int curMax = 0, njumps = 0, i = 0;
        while(curMax<n-1) {
            int lastMax = curMax;
            for(; i<=lastMax; i++) 
                curMax = max(curMax,i+nums[i]);
            njumps++;
            if(lastMax == curMax) return -1;
        }
        return njumps;
    }
};
