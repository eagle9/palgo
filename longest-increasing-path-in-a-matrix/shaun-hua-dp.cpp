//hua's dp, shaun quick read, the order is key to make dp work
// dfs with memo is more natural and easier approach
//runtime 68ms, faster than 36%, mem less than 33%
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 1)); //init with 1
        int ans = 0;
        
        //store value and its xy
        vector<pair<int, pair<int, int>>> cells;
        for (int y = 0; y < m; ++y)
            for (int x = 0; x < n; ++x)
            cells.push_back({matrix[y][x], {x, y}});
    
        //sort(cells.rbegin(), cells.rend());
        sort(cells.begin(), cells.end(), greater<pair<int,pair<int,int>>>());
        vector<vector<int>> delta {{0, 1}, {0, -1}, {1,0}, {-1,0}};
        //consider larger value first, it will be populated with ans first
        // then smaller value, its answer will be ++ from larger value
        //this shows the importance of computer order in DP
        for (const auto& cell : cells) {
            int x = cell.second.first;
            int y = cell.second.second;
            for (int i = 0; i < 4; ++i) {
                int tx = x + delta[i][0];
                int ty = y + delta[i][1];
                if (tx < 0 || tx >= n || ty < 0 || ty >= m) continue;
                if ( matrix[y][x] >= matrix[ty][tx]) continue;
                dp[y][x] = max(dp[y][x], 1 + dp[ty][tx]);            
            }
            ans = max(ans, dp[y][x]);
        }
        return ans;
    }
};
