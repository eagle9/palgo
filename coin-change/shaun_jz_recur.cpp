/*
shaun try with jz dp class recursion
added memo, without memo, TLE
with memo, runtime 544ms, faster than 6.5%

*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>()); //greater in front
        int res = helper(coins, amount);
        return res == INT_MAX? -1: res;
    }
    
    
private:
    unordered_map<int,int> memo;
    int helper(vector<int>& coins, int amount) {
        if (memo.count(amount)) return memo[amount];
        if (amount == 0) return 0;
        int res = INT_MAX;
        for (int coin: coins) {
            if (coin <= amount) {
                int res1 = helper(coins, amount - coin);
                res = min(res,  res1 == INT_MAX? INT_MAX : 1 + res1);
            }
            
        }
        memo[amount] = res;
        return res;
    }
};
