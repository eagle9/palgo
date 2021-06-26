/*

huahua use dfs
Runtime: 28 ms, faster than 59.93% of C++ online submissions for Max Area of Island.
Memory Usage: 14.5 MB, less than 75.89% of C++ online submissions for Max Area of Island.
*/
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h = grid.size();
        if (h == 0) return 0;
        int w = grid[0].size();
        
        int ans = 0;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                ans = max(ans, area(grid, j, i, w, h));
        return ans;
    }
private:
    int area(vector<vector<int>>& grid, int x, int y, int w, int h) {
        if (x < 0 || y < 0 || x >= w || y >= h || grid[y][x] == 0) return 0;
        
        grid[y][x] = 0;
        
        return area(grid, x - 1, y, w, h) 
             + area(grid, x + 1, y, w, h)
             + area(grid, x, y - 1, w, h)
             + area(grid, x, y + 1, w, h)
             + 1;            
    }
};

