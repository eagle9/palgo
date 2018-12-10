//grandyang, beats 54%
/*
四个累加数组v1, v2, v3, v4，其中v1是水平方向从左到右的累加数组，v2是水平方向从右到左的累加数组，v3是竖直方向从上到下的累加数组，v4是竖直方向从下到上的累加数组，我们建立好这个累加数组后，对于任意位置(i, j)，其可以炸死的最多敌人数就是v1[i][j] + v2[i][j] + v3[i][j] + v4[i][j]

*/
class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        vector<vector<int>> v1(m, vector<int>(n, 0)), v2 = v1, v3 = v1, v4 = v1;
        for (int i = 0; i < m; ++i) {
            //from left to right
            for (int j = 0; j < n; ++j) {
                //for v1[i][j], init with 0 or v1[i][j-1]
                int t = (j == 0 || grid[i][j] == 'W') ? 0 : v1[i][j - 1];
                //check grid[i][j], 
                v1[i][j] = grid[i][j] == 'E' ? t + 1 : t;
            }
            //from right to left
            for (int j = n - 1; j >= 0; --j) {
                int t = (j == n - 1 || grid[i][j] == 'W') ? 0 : v2[i][j + 1];
                v2[i][j] = grid[i][j] == 'E' ? t + 1 : t;
            }
        }
        for (int j = 0; j < n; ++j) {
            //from up to down
            for (int i = 0; i < m; ++i) {
                int t = (i == 0 || grid[i][j] == 'W') ? 0 : v3[i - 1][j];
                v3[i][j] = grid[i][j] == 'E' ? t + 1 : t;
            }
            //from down to up
            for (int i = m - 1; i >= 0; --i) {
                int t = (i == m - 1 || grid[i][j] == 'W') ? 0 : v4[i + 1][j];
                v4[i][j] = grid[i][j] == 'E' ? t + 1 : t;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0') {
                    res = max(res, v1[i][j] + v2[i][j] + v3[i][j] + v4[i][j]);
                }
            }
        }
        return res;
    }
};
