/*
grandyang dp idea, shaun initially only come up with 1 d prefix sum
grandyang 2d dp is 2d prefix sum, draw pictures to figure out the rectangles
cutting dynamic programming dp[i][j], sum from 0,0 to i-1,j-1
runtime 20ms, faster than 94%, mem less than 17%
*/
class NumMatrix {
public:
    NumMatrix(vector<vector<int> > matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        dp.resize(m + 1, vector<int>(n + 1, 0));
        //dp[i][j] region sum from 00 to i-1,j-1
        for (int i = 1; i <= matrix.size(); ++i) {
            for (int j = 1; j <= matrix[0].size(); ++j) {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] - dp[row2 + 1][col1] + dp[row1][col1];
    }
    
private:
    vector<vector<int> > dp;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
