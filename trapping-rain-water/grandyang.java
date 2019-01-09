/*
grandyang two pointer idea, beats 31%
遍历一次即可的解法，这个算法需要left和right两个指针分别指向数组的首尾位置，从两边向中间扫描，在当前两指针确定的范围内，先比较两头找出较小值，如果较小值是left指向的值，则从左向右扫描，如果较小值是right指向的值，则从右向左扫描，若遇到的值比当较小值小，则将差值存入结果，如遇到的值大，则重新确定新的窗口范围，以此类推直至left和right指针重合
*/
class Solution1 {
    public int trap(int[] height) {
        int res = 0, left = 0, right = height.length - 1;
        while (left < right) {
            int mn = Math.min(height[left], height[right]);
            if (mn == height[left]) {
                ++left;
                while (left < right && height[left] < mn) {
                    res += mn - height[left++]; //water amount at position left
                }
            } else {
                --right;
                while (left < right && height[right] < mn) {
                    res += mn - height[right--];
                }
            }
        }
        return res;
    }
}

/*
用stack来做的，博主一开始都没有注意到这道题的tag还有stack，所以以后在总结的时候还是要多多留意一下标签啊。其实用stack的方法博主感觉更容易理解，我们的做法是，遍历高度，如果此时栈为空，或者当前高度小于等于栈顶高度，则把当前高度的坐标压入栈，注意我们不直接把高度压入栈，而是把坐标压入栈，这样方便我们在后来算水平距离。当我们遇到比栈顶高度大的时候，就说明有可能会有坑存在，可以装雨水。此时我们栈里至少有一个高度，如果只有一个的话，那么不能形成坑，我们直接跳过，如果多余一个的话，那么此时把栈顶元素取出来当作坑，新的栈顶元素就是左边界，当前高度是右边界，只要取二者较小的，减去坑的高度，长度就是右边界坐标减去左边界坐标再减1，二者相乘就是盛水量啦
grandyang idea with stack, beats only 9%, not fully understood. actually not natural for me to understand
*/
class Solution {
    public int trap(int[] height) {
        Stack<Integer> s = new Stack<Integer>();
        int i = 0, n = height.length, res = 0;
        while (i < n) {
            if (s.isEmpty() || height[i] <= height[s.peek()]) {
                s.push(i++);
            } else {
                int t = s.pop();
                if (s.isEmpty()) continue;
                res += (Math.min(height[i], height[s.peek()]) - height[t]) * (i - s.peek() - 1);
            }
        }
        return res;
    }
}
