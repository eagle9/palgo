class Solution {
    public int minAreaRect(int[][] points) {
        Map<Integer, Set<Integer>> s = new HashMap<>();
        for (int [] point : points) {
            s.putIfAbsent(point[0], new HashSet<>());
            s.get(point[0]).add(point[1]);
        }
    
        int n = points.length;
        int minArea = Integer.MAX_VALUE;
        for (int i = 0; i < n; ++i)
          for (int j = i + 1; j < n; ++j) {
            int x0 = points[i][0];
            int y0 = points[i][1];
            int x1 = points[j][0];
            int y1 = points[j][1];
            if (x0 == x1 || y0 == y1) continue;
            // x0y0          x0y1?
            // x1y0?         x1y1
            if (!s.get(x1).contains(y0) || !s.get(x0).contains(y1)) continue;

            int area = Math.abs(x0 - x1) * Math.abs(y0 - y1);
            minArea = Math.min(minArea,area);
          }
        return minArea == Integer.MAX_VALUE ? 0 : minArea;
    }
}

//hua and shaun cutting: for each pair of points x0y0 one corner, x1y1 as the other diagonal corner, 
//derive the other two corners and check if they are in the given point list
//update the min area with a loop of O(n^2)
//runtime 128ms, faster than 92%, mem less than 59%

