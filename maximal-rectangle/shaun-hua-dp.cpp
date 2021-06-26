//hua 2d dp, shaun read and understand, rewrite for better thought process
//runtime 20ms, faster than 96%, mem less than 63%
class Solution {
public:
  int maximalRectangle(vector<vector<char> > &matrix) {
    if (matrix.empty()) return 0;
    int r = matrix.size();
    int c = matrix[0].size();
  
    // dp[i][j] := max len of all 1s ends with col j at row i.
    vector<vector<int>> dp(r, vector<int>(c));
 
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (matrix[i][j] == '1') 
                dp[i][j] = (j == 0) ? 1 : dp[i][j - 1] + 1; //j==0? is natural dealing with j-1 index
            else dp[i][j] = 0; //reset
        }
    }    
 
    int ans = 0;
    
    //enumerate all ractangles
    //for any ending col j
    //for any rectangle height k - i +1, from row i to k>=i, find a col j where longest 1 seq ends
    for (int j = 0; j < c; ++j) {
        for (int i = 0; i < r; ++i){
            int width = INT_MAX; //find the narrowest width from row i
            for (int k = i; k < r; k++) {
                width = min(width, dp[k][j]);
                if (width == 0) break; //no need to try more rows, determined by the narrowest
                ans = max(width * (k - i + 1), ans);
            }
        }
    }
 
    return ans;
  }
};
