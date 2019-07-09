//grandyang dfs idea, similar to my own thoughts about dfs depth is the area of island
//    more natural than hua's dfs
//runtime 52ms, faster than 8%, mem less than 8%
class Solution {
public:
    vector<vector<int>> dirs{{0,-1},{-1,0},{0,1},{1,0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), res = 0;
        //try all starting island cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] != 1) continue;
                int cnt = 0;
                helper(grid, i, j, cnt, res);
            }
        }
        return res;
    }
    
    //void helper(vector<vector<int>>& grid, int i, int j, int cnt, int& res) { //bug wrong answer
    //why cnt has to be reference varialbe????
    //i see, res is global, max area of all islands
    //  cnt is local for each ij, from that point on, cnt has to be used for accumulation
    void helper(vector<vector<int>>& grid, int i, int j, int& cnt, int& res) {
        int m = grid.size(), n = grid[0].size();
        //recur exit base case, out bound or not visited
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= 0) return;
        res = max(res, ++cnt); //why ++cnt, because init call cnt = 0
        grid[i][j] *= -1; //mark visited, clever with grid itself, rather than extra array
        for (auto dir : dirs) {
            helper(grid, i + dir[0], j + dir[1], cnt, res);
        }
    }
};
