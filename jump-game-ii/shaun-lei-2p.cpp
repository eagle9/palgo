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
/*

[解题思路]
二指针问题，最大覆盖区间。
从左往右扫描，维护一个覆盖区间，每扫过一个元素，就重新计算覆盖区间的边界。比如，开始时区间[start, end], 遍历A数组的过程中，不断计算A[i]+i最大值（即从i坐标开始最大的覆盖坐标），并设置这个最大覆盖坐标为新的end边界。而新的start边界则为原end+1。不断循环，直到end> n.

runtime 12ms, faster than 85%, mem less than 90%

*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
       
        int start = 0;  
        int end = 0;  
        int count =0;  
        if(n == 1) return 0;  
        while(end < n)  {  
            int max1 = 0;  
            count++;  
            for(int i =start; i<= end ; i++ )  {   
                if(nums[i]+i >= n-1)  return count;  
            
                if(nums[i]+ i > max1)  max1 = nums[i]+i;
            }
          
            start = end+1;  
            end = max1;
        }
        return count;
    }  
}; 
