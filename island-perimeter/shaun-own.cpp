//shaun own idea: consider each island cell's contribution by checking neighbors
//example 3 + , assumption exactly 1 island, no lakes 
/*
Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
      3 
+ 3 + 0 + 3
     +2
 +3 + 2
 total = 3 + 6 + 2 + 5 = 16
 shaun's own idea, accepted after 1 buf fix(vector assignment in side function)
 runtime 196ms, faster than 5%, mem less than 5%
*/
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        if (grid.empty()) return 0;
        m = grid.size();
        n = grid[0].size();
        deltas = {{1,0},{-1,0},{0,1},{0,-1}};
        
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
                res += 4- helper(grid, i, j); //each island cell(==1) contribution
            }
        }
        return res;
    }
private:
    int m, n;
    vector<vector<int>> deltas; //= {{1,0},{-1,0},{0,1},{0,-1}}; //bug can not assign here
    //get ij's neighboring island neighbor count
    int helper(vector<vector<int>>& grid, int i, int j) {
        int res = 0;
        for (auto d: deltas) {
            int ni = i + d[0], nj = j + d[1];
            if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
            if (grid[ni][nj] == 1) res++;
        }
        return res;
    }
};
