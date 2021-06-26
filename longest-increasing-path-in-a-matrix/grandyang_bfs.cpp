/*
Runtime: 1832 ms, faster than 2.08% of C++ online submissions for Longest Increasing Path in a Matrix.
Memory Usage: 401.4 MB, less than 0.82% of C++ online submissions for Longest Increasing Path in a Matrix.
grandyang bfs, understood Feb 13 2019 
*/
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 1;
        vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j ) {
                if (dp[i][j] > 0) continue;
                queue<pair<int, int>> q{{{i, j}}};
                int cnt = 1;
                while (!q.empty()) {
                    //++cnt;
                    int len = q.size();
                    //all it neighbors at the same depth in the q now
                    for (int k = 0; k < len; ++k) {
                        auto t = q.front(); q.pop();
                        for (auto dir : dirs) {
                            int x = t.first + dir[0], y = t.second + dir[1];
                            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[t.first][t.second] || cnt+1  <= dp[x][y]) continue;
                            dp[x][y] = cnt+1;
                            res = max(res, cnt+1);
                            //q.push({x, y});
                            q.push(make_pair(x,y));
                        }
                    }
                    cnt = cnt+1;
                }
            }
        }
        return res;
    }
};
