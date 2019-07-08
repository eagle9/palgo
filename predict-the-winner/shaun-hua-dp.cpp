//hua dp minimax, 
//runtime 0ms, faster than 100%, mem less than 45%
//i am puzzled that i don't see the score add up, understand now
//every step substract other player's score, okay makes sense now
//cutting angle, think of the net score, each time player 1 take one score left or right
//// player 2 score is recusion of smaller problem
class Solution {
public:
bool PredictTheWinner(vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
    
    for (int i = 0; i < n; ++i) dp[i][i] = nums[i];
      
    //compute in the order of len
    for (int len = 2; len <= n; ++len) {
        //start index i
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            //take nums[i], other player score dp[i+1][j]
            //take nums[j], other player score dp[i][j-1]
            //i am puzzle, this is the net score at the moment
            dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1] >= 0;
  }
};

