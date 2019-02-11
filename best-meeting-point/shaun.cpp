/*
grandyang math and sort idea, shaun cpp code from idea
draw and use math to find idea

Runtime: 12 ms, faster than 100.00% of C++ online submissions for Best Meeting Point.
Memory Usage: 6.5 MB, less than 0.90% of C++ online submissions for Best Meeting Point.

*/
class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> y, x;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    y.push_back(i);
                    x.push_back(j);
                }
            }
        }
        return minDist1D(y) + minDist1D(x);
    }
    
    int minDist1D(vector<int> &y) {
        sort(y.begin(), y.end());
        int i = 0, j = y.size() - 1, res = 0;
        
        while (i < j) res += y[j--] - y[i++];
        return res;
    }
};
