//shaun's original idea, runtime 12ms, faster than 99%, memory less than 35%
class Solution1 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;
        //now m >0 and n > 0
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                //from up or left
                dp[i][j] = min( dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
        
    }
};

//shaun try space reduction, al rolling array --> wrong answer
//runtime 12ms, faster than 99%, 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;
        //now m >0 and n > 0
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> dp(2, vector<int>(n));
        //dp[0][0] = grid[0][0];
        
        int cur = 1,prev = 0; //which one is 0 matter???? why? 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    //dp[i][j] = ... not good, why???
                    dp[cur][j] = grid[i][j];
                    continue;
                }
                //from up or left
                //i == 0, only consider from left, make up contribution max in min
                int up = (i == 0)? INT_MAX: dp[prev][j];
                
                //j == 0, only consider from up, make left contri max in min
                int left = (j ==0)? INT_MAX: dp[cur][j-1];
                int from = min(up,left);
                //i == 0, j == 0, from = MAX
                //dp[cur][j] = (from == INT_MAX)?0: from  + grid[i][j];
                dp[cur][j] =  from + grid[i][j];
            }
            swap(cur, prev);
            
        }
        //after swap, stored in prev
        return dp[prev][n-1];
        
    }
};

//jz rolling array, runtime 12ms, faster than 99%
class Solution3 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        if (grid[0].empty()) return 0;
        //now m >0 and n > 0
        int m = grid.size(), n = grid[0].size();
        
        vector<vector<int>> f(2, vector<int>(n));
        int prev = 1, cur = 0; // f[i] is stored in rolling array f[0]
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) {
                    f[cur][j] = grid[0][0];
                    continue;
                }
                
                f[cur][j] = INT_MAX;
                if (i > 0) {
                    f[cur][j] = min(f[cur][j], f[prev][j]);
                }//else int_max
                
                if (j > 0) {
                    f[cur][j] = min(f[cur][j], f[cur][j - 1]);
                }//else int_max
                
                f[cur][j] += grid[i][j];
            }
            swap(prev,cur);
            
        }
        
        return f[prev][n - 1];
        
    }
};
