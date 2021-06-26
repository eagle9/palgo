/*
first get number of empty squares to ensure we go from start to end and passing all empty squares

dfs(grid, x, y, n) return the number of paths from xy to end

do some test:
[[1,0,0,0],
 [0,0,0,0],
 [0,0,2,-1]]
 
 shaun own try with hua dfs idea, wrong answer, count init with 0(should be 1)
 be clear with the number of squares along the path before reaching the end
 runtime 0ms, faster than 100%, mem less than 100%
 
 runtime 4ms, faster than 79%, mem less than 100%
 
 time O(4^(m*n)), space O(m*n)
*/
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m_ = grid.size();
        n_ = grid[0].size();
        
        //int count = 0; //bug init with 0
        int count = 1; //starting square ==1, should be considred, so count is the number of squares before reaching the end, which the number of 0 cells plus 1
        int x = -1, y = -1; //xy of starting square
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (grid[i][j] == 0) count++;
                else if (grid[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }
        
        return dfs(grid, x, y, count);
    }
private:
    int m_, n_;
    //return number of paths from xy to the ending square
    int dfs(vector<vector<int>>&grid, int x, int y, int count) {
        if (x < 0 || x >= m_ || y < 0 || y >= n_) return 0; //xy out bound
        if (grid[x][y] == -1) return 0;
        
        if (grid[x][y] == 2) return count == 0?1:0; //already at the end, 1 if count ==0
        //if (grid[x][y] == -1) return 0;
        // == 0 or == 1
        //==0
        grid[x][y] = -1;
        int paths = 
            dfs(grid, x+1, y, count-1) +
            dfs(grid, x-1, y, count-1) +
            dfs(grid, x, y+1, count-1) +
            dfs(grid, x, y-1, count-1);
        grid[x][y] = 0;
        return paths;
        
    }
};


