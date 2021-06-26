//grandyang, similar to mine, without sub function call, faster, focus on water neighbor direclty
//runtime 68ms, faster than 81%, mem less than 99%
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size(), res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                if (j == 0 || grid[i][j - 1] == 0) ++res; //left water? 
                if (i == 0 || grid[i - 1][j] == 0) ++res; //up water?
                if (j == n - 1 || grid[i][j + 1] == 0) ++res; //right water?
                if (i == m - 1 || grid[i + 1][j] == 0) ++res; //down water?
            }
        }
        return res;
    }
};
