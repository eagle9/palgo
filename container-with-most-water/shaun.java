/*
和那道 Trapping Rain Water 收集雨水 很类似，但又有些不同，那道题让求整个能收集雨水的量，这道只是让求最大的一个的装水量，而且还有一点不同的是，那道题容器边缘不能算在里面，而这道题却可以算，相比较来说还是这道题容易一些，我们需要定义i和j两个指针分别指向数组的左右两端，然后两个指针向中间搜索，每移动一次算一个值和结果比较取较大的，容器装水量的算法是找出左右两个边缘中较小的那个乘以两边缘的距离，
grandyang idea1, shaun come up with the same idea, not clear with two pointer moving though,  beats 50%
*/
class Solution {
    public int maxArea(int[] height) {
        int res = 0;
        int left = 0, right = height.length-1;
        while (left < right) {
            int area = (right -left) * Math.min(height[left], height[right]);
            if (area > res) res = area;
            if (height[left] < height[right]) {
                left++;
            }else {
                right--;
            }
        }
        return res;
    }
}
/*
//grandyang idea2, beats 56%
对上面的方法进行了小幅度的优化，对于相同的高度们直接移动i和j就行了，不再进行计算容量了
*/
public class Solution2 {
    public int maxArea(int[] height) {
        int res = 0, i = 0, j = height.length - 1;
        while (i < j) {
            int h = Math.min(height[i], height[j]);
            res = Math.max(res, h * (j - i));
            while (i < j && h == height[i]) ++i;
            while (i < j && h == height[j]) --j;
        }
        return res;
    }
}
