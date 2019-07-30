/*hua hash and geometry idea
chech any 3 points p1p2 and p1p3 vertical to each other, derive p4's x and y, check if p4 is in the given points. if yes, update the min area
shaun did came up the idea check any 3 points p1p2 perpendicular to p1p3

runtime 68ms, faster than 49%, mem less than 65%
*/
class Solution {
public:
  double minAreaFreeRect(vector<vector<int>>& points) {
    constexpr double INF_AREA = 1e100;
    const auto n = points.size();
    //unordered_set<int> s;
    unordered_map<int, unordered_set<int>> m;
    for (const auto& p : points) {
      //s.insert(p[0] << 16 | p[1]); //combine x and y into 32 bits
      //assume x and y won't be greater than 1<<16, or 65536
      m[p[0]].insert(p[1]);
    }
    double min_area2 = INF_AREA;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        for (int k = 0; k < n; ++k) {
          if (i == k || j == k) continue;
          const auto& p1 = points[i];
          const auto& p2 = points[j];
          const auto& p3 = points[k];
          //two vectors p1->p2, p1->p3, are they vertical to each other
          //       x2-x1        x3-x1
          //       y2-y1        y3-y1
          //use dot product
          int dot = (p2[0] - p1[0]) * (p3[0] - p1[0]) +
                    (p2[1] - p1[1]) * (p3[1] - p1[1]);
          if (dot != 0) continue; //skip when not vertical/perpendicular
          //why p4's x y can be this way, thinking the center of the rectangle rotating
          int p4_x = p2[0] + p3[0] - p1[0];
          int p4_y = p2[1] + p3[1] - p1[1];
          //if (!s.count(p4_x << 16 | p4_y)) continue; //p4 not found skip
          if (!m[p4_x].count(p4_y)) continue;
          //p1p2^2   a^2
          //p1p3^2   b^2
            //area = len(p1p2) * len(p1p3) = ab
          double a = pow(p2[0] - p1[0], 2) + pow(p2[1] - p1[1], 2);
          double b = pow(p3[0] - p1[0], 2) + pow(p3[1] - p1[1], 2);
          double area2 = a * b;
          min_area2 = min(min_area2, area2);
        }
      }
      
    return min_area2 < INF_AREA ? sqrt(min_area2) : 0; //sqrt key here
  }
};
