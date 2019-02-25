/*
grandyang dfs2
Runtime: 92 ms, faster than 24.68% of C++ online submissions for Number of Distinct Islands.
Memory Usage: 30.4 MB, less than 37.93% of C++ online submissions for Number of Distinct Islands.

*/
class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int, int>>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                vector<pair<int, int>> v;
                helper(grid, i, j, i, j, v);
                res.insert(v);
            }
        }
        return res.size();
    }
    void helper(vector<vector<int>>& grid, int x0, int y0, int i, int j, vector<pair<int, int>>& v) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) return;
        grid[i][j] *= -1;
        v.push_back({i - x0, j - y0});
        for (auto dir : dirs) {
            helper(grid, x0, y0, i + dir[0], j + dir[1], v);
        }
    }
};
