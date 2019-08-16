//grandyang dfs idea2, cutting normalize xy from starting point, 
//push all x-x0, y-y0 pairs into v, same shape should have the same vector of pairs
//cutting: same shape will be visited in the same path
//runtime 76ms, faster than 20%, mem less than 14%
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
    //starting point x0 y0 used to normalize
    void helper(vector<vector<int>>& grid, int x0, int y0, int i, int j, vector<pair<int, int>>& v) {
        int m = grid.size(), n = grid[0].size();
        //skip out bound, or grid[i][j] == 0, or ij visited ==-1
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) return;
        grid[i][j] *= -1; //mark ij visited, < 0 now
        v.push_back({i - x0, j - y0}); //encode the island visit path into v
        for (auto dir : dirs) {
            helper(grid, x0, y0, i + dir[0], j + dir[1], v);
        }
    }
};
