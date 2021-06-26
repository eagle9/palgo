/*
try all start point
track maxGold init with INT_MAX
vector<vector<bool>> visited(m,vector<bool>(n))
dfs(v, i, j, curGold)

*/


//lt discuss and shaun modified to his own template and understanding
//runtime 132ms, faster than 22%, mem less than 100%
class Solution {
private:
    int m,n;
     //return maxGold starting from xy
     int dfs(vector<vector<int>>& grid, int x, int y, vector<vector<bool>>& visited) {
        int maxGold = 0;
        
         //outbound or visited already
        if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y]) return 0;
        visited[x][y] = true;
        if (grid[x][y] == 0) return 0;
        
        maxGold = max(maxGold, dfs(grid, x + 1, y, visited));
        maxGold = max(maxGold, dfs(grid, x - 1, y, visited));
        maxGold = max(maxGold, dfs(grid, x, y + 1, visited));
        maxGold = max(maxGold, dfs(grid, x, y - 1, visited));
         //back track
        visited[x][y] = false;
        
        return grid[x][y] + maxGold;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = INT_MIN;
        m = grid.size();
        n = grid[0].size();
        //try all starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<vector<bool>> visited(m,vector<bool>(n,false));
                maxGold = max(maxGold, dfs(grid, i, j, visited));
                
            }
        }
        return maxGold;
    }
};

