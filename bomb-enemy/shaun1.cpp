typedef vector<int> vi;
typedef vector<vi> vvi;

//shaun's original idea, first sub wrong answer
//modified, try to get f[][] for # of e at row, and g[][] for # of e at col
//left to right, and right to left
//up to down, down to up update
//modified code with test case failure, finally accepted
//runtime 40ms, faster than 42%, memory less than 15%
//time O(n^2)

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vvi f(m, vi(n));
        vvi g(m, vi(n));
        for (int i = 0; i < m; ++i) {
            //from left to right
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0')
                    f[i][j] = (j==0)? 0 : f[i][j-1];
                else if (grid[i][j] == 'E')
                    f[i][j] = (j==0)? 1 : f[i][j-1]+1;
                else // ==W
                    f[i][j] = 0;
            }
            //from right to left, pass enemy count back to left side
            for(int j = n-1; j >=1; --j) {
                if (grid[i][j-1] == '0' || grid[i][j-1] == 'E') 
                    f[i][j-1] = grid[i][j] == 'W'? f[i][j-1]: f[i][j];
                
            }
        }
        for (int j = 0; j < n; ++j) {
            //from up to down
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == '0')
                    g[i][j] = (i==0)? 0 : g[i-1][j];
                else if (grid[i][j] == 'E')
                    g[i][j] = (i==0)? 1 : g[i-1][j]+1;
                else // ==W
                    g[i][j] = 0;
            }
            //from down to up
            for(int i = m-1; i >=1; --i) {
                if (grid[i-1][j] == '0' || grid[i-1][j] == 'E') 
                    g[i-1][j] = grid[i][j] == 'W'? g[i-1][j]: g[i][j];
                
            }
        }
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '0')
                    res = max(res,f[i][j] + g[i][j]);
            }
        }
        return res;
        
    }
};
