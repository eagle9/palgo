//grandyang and shaun's naive dfs with path encoding, this is the cut
//I have come up the idea to encode the path, but not entirely clear with details
//runtime 108ms, faster than 8%, mem less than 14%
class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    int numDistinctIslands(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        //island path encoding string
        unordered_set<string> res;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                //dfs for each unvisited island cell
                if (grid[i][j] == 1 && !visited[i][j]) {
                    set<string> s;
                    helper(grid, i, j, i, j, visited, s);
                    //aggregate all steps into t and save into res
                    string t = "";
                    for (auto str : s) t += str + "_";
                    res.insert(t);
                }
            }
        }
        return res.size();
    }
    //x0 y0 the starting point, 
    //dfs from ij, each step insert into s
    void helper(vector<vector<int>>& grid, int x0, int y0, int i, int j, vector<vector<bool>>& visited, set<string>& s) {
        int m = grid.size(), n = grid[0].size();
        visited[i][j] = true;
        for (auto dir : dirs) {
            int x = i + dir[0], y = j + dir[1];
            if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 0 || visited[x][y]) continue;
            string str = to_string(x - x0) + "_" + to_string(y - y0);
            s.insert(str);
            helper(grid, x0, y0, x, y, visited, s);
        }
    }
};
