/*
huahua
Runtime: 24 ms, faster than 92.31% of C++ online submissions for Making A Large Island.
Memory Usage: 13.4 MB, less than 56.41% of C++ online submissions for Making A Large Island.

*/
class Solution {
public:
  int largestIsland(vector<vector<int>>& grid) {
    color_ = 1;
    g_ = &grid;
    m_ = grid.size();
    n_ = grid[0].size();
    unordered_map<int, int> areas; // color -> area
    int ans = 0;
    for (int i = 0; i < m_; ++i)
      for (int j = 0; j < n_; ++j)
        if (grid[i][j] == 1) {
          ++color_;
          areas[color_] = getArea(j, i);
          ans = max(ans, areas[color_]);
        }
    for (int i = 0; i < m_; ++i)
      for (int j = 0; j < n_; ++j)
        if (grid[i][j] == 0) {                    
          int area = 1;
          for (int color : set<int>{getColor(j, i - 1), getColor(j, i + 1),
                                    getColor(j - 1, i), getColor(j + 1, i)}) 
            area += areas[color];
          ans = max(ans, area);
        }
    return ans;
  }
private:
  int m_;
  int n_;
  int color_;
  vector<vector<int>>* g_; // does not own the object.
  
  int getColor(int x, int y) {
    return (x < 0 || x >= n_ || y < 0 || y >= m_) ? 0 : (*g_)[y][x];
  }
  
  // Return the area of a connected component, set all elements to color_.
  int getArea(int x, int y) {
    if (x < 0 || x >= n_ || y < 0 || y >= m_ || (*g_)[y][x] != 1) return 0;
    (*g_)[y][x] = color_;
    return 1 + getArea(x - 1, y) + getArea(x + 1, y) 
             + getArea(x, y - 1) + getArea(x, y + 1);
  }
};
