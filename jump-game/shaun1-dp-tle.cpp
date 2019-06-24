/*shaun own idea and c++ code
TLE
*/
class Solution {
public:
    bool canJump(vector<int> nums) {
        int n = nums.size();
        vector<bool> dp(n);//init with all false
        if (n == 1) return true; //already at index 0
        dp[0] = true;
       
        for (int i = 1; i < n; i++) {
            //try to reach i from j
            for (int j = 0; j < i; j++) {
                if (dp[i]) continue; //if dp[i] already turned true
                else //update dp[i]
                    dp[i] = dp[j] && nums[j] >= i-j; //wrong answer when use == at first, when changed to >=, accepted. so go over is considered reachable. clarify with officer
            }
        }
        return dp[n-1];
    
    }
};
