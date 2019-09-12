/*
grandyang math and sort idea, shaun cpp code from idea
draw and use math to find idea
manhattan distance can be separated to x and y completely
P inside AB to get minimized distance
outside AB won't be minimized.  P can be any point inside AB
so naturally we want to sort the x values and y values, 
C_____A_____P_______B______D

runtime 8ms, faster than 68%, mem less than 67%


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
    
    //y.size is even, all paired
    //y.size is odd, left and right point to the same value, best meeting point, distance is zero, 
    int minDist1D(vector<int> &y) {
        sort(y.begin(), y.end());
        int left = 0, right = y.size() - 1, dist = 0;
        while (left < right) dist += y[right--] - y[left++];
        return dist;
    }
};
