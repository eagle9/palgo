//hua dfs with memo, shaun rewrite and accepted after 1 bug fix
//cutting angle ---> neighbor, for each starting point at i,j
// 4 neighbors longest inc path, if ij < any neighbor, then 1+ longest inc path
//follow up, print out the longest inc path??? can you do it? 
//yes i can do it, check my comment in the code
//runtime 44ms, faster than 97%, mem less than 53%
//Time complexity: O(mn)
//Space complexity: O(mn)

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        m = matrix.size(); //number of rows, i from 0 to m-1
        n = matrix[0].size(); //number of cols, j from 0 to n-1
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j ) {
                ans = max(ans, dfs(matrix, i, j));
                //record starting point ij if asked to print out the path
            }
        return ans;
        
        //dfs from ij and find the max inc path
    }
private:
    //return longest inc path start from row i col j
    int dfs(const vector<vector<int>>& mat, int i, int j) {
        if (memo[i][j] != -1) return memo[i][j];
        // right, left,   down, up 
        static int di[] = {0, 0, 1, -1};
        static int dj[] = {1, -1, 0, 0};
        memo[i][j] = 1;
        for (int k = 0; k < 4; ++k) {
            int ni = i + di[k];
            int nj = j + dj[k];
            //skip out bound
            //want ij < ni nj, so skip ij >= ni nj
            //if (ni < 0 || nj < 0 || ni >= m || ni >= n || mat[i][j] >= mat[ni][nj]) continue; //bug 1, typo
            if (ni < 0 || ni >= m || nj < 0 || nj >= n || mat[i][j] >= mat[ni][nj]) continue;
            //now ni nj in bound, and ij < ni,nj
            memo[i][j] = max(memo[i][j], 1 + dfs(mat, ni, nj));
        }
        return memo[i][j];
  }
private:  
    int m;  //number of rows
    int n;  //number of cols, add _suffix after acceptance
    // memo[i][j]: max length of increasing path start from (i, j)
    vector<vector<int>> memo;  
};
