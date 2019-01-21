/*
grandyang idea1, runtime 55ms, faster than 22%
not yet understand
此题是之前那道的 Largest Rectangle in Histogram 直方图中最大的矩形 的扩展，这道题的二维矩阵每一层向上都可以看做一个直方图，输入矩阵有多少行，就可以形成多少个直方图，对每个直方图都调用 Largest Rectangle in Histogram 直方图中最大的矩形 中的方法，就可以得到最大的矩形面积。那么这道题唯一要做的就是将每一层构成直方图，由于题目限定了输入矩阵的字符只有 '0' 和 '1' 两种，所以处理起来也相对简单。方法是，对于每一个点，如果是‘0’，则赋0，如果是 ‘1’，就赋 之前的height值加上1

*/
class Solution {
    public int maximalRectangle(char[][] matrix) {
        if (matrix.length == 0 || matrix[0].length == 0) return 0;
        int res = 0, m = matrix.length, n = matrix[0].length;
        int [] height = new int[n + 1];
        
        for (int i = 0; i < m; ++i) {
            Stack<Integer> s = new Stack<>();
            for (int j = 0; j < n + 1; ++j) {
                if (j < n) {
                    height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
                }
                while (!s.isEmpty() && height[s.peek()] >= height[j]) {
                    int cur = s.pop();
                    res = Math.max(res, height[cur] * (s.isEmpty() ? j : (j - s.peek() - 1)));
                }
                s.push(j);
            }
        }
        return res;
    }
}
