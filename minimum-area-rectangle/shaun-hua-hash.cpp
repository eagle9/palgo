//hua and shaun cutting: for each pair of points x0y0 one corner, x1y1 as the other diagonal corner, 
//derive the other two corners and check if they are in the given point list
//update the min area with a loop of O(n^2)
//runtime 128ms, faster than 92%, mem less than 59%
class Solution {
public:
  int minAreaRect(vector<vector<int>>& points) {    
    unordered_map<int, unordered_set<int>> s;
    for (const auto& point : points)
      s[point[0]].insert(point[1]);
    
    const int n = points.size();
    int min_area = INT_MAX;
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) {
        int x0 = points[i][0];
        int y0 = points[i][1];
        int x1 = points[j][0];
        int y1 = points[j][1];
        if (x0 == x1 || y0 == y1) continue;
        // x0y0          x0y1?
        // x1y0?         x1y1
        if (!s[x1].count(y0) || !s[x0].count(y1)) continue;
          
        int area = abs(x0 - x1) * abs(y0 - y1);
        min_area = min(min_area,area);
      }
    return min_area == INT_MAX ? 0 : min_area;
  }
};
