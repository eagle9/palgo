/*
grandyang dp idea
cutting: 
用DP来求解的问题。那么其实我们可以不新建dp数组，而是直接复用triangle数组，我们希望一层一层的累加下来，从而使得 triangle[i][j] 是从最顶层到 (i, j) 位置的最小路径和，那么我们如何得到状态转移方程呢？其实也不难，因为每个结点能往下走的只有跟它相邻的两个数字，那么每个位置 (i, j) 也就只能从上层跟它相邻的两个位置过来，也就是 (i-1, j-1) 和 (i-1, j) 这两个位置，那么状态转移方程为：

triangle[i][j] = min(triangle[i - 1][j - 1], triangle[i - 1][j])

runtime 4ms, faster than 97%, mem less than 100%
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); ++i) {
            int n = triangle[i].size();
            for (int j = 0; j < n ; ++j) {
                if (j == 0) {
                    triangle[i][j] += triangle[i - 1][j];
                } else if (j == n - 1) {
                    triangle[i][j] += triangle[i - 1][j - 1];
                } else {
                    triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }
        vector<int>& last_row = triangle.back();
        return *min_element(last_row.begin(), last_row.end());
    }
};
