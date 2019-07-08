//shaun first try with jz recursion idea
//key thoughts: 1) may not have answer how to deal it, special value for no solution, INT_MAX
//2) min of the all branches
//3) know to use memo to speed up, repetitive smaller problems
//runtime 428ms, faster than 74%, mem less than 8%
//wrong answer, then TLE, finally accepted
class Solution000 {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        int res = 0;
        if (helper(coins, amount,res)) return res;
        return -1;
    }
private:
    bool helper(vector<int>& coins, int amount, int& res) {
        if (amount == 0) return true;
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = amount/coins[i]; j>=1; --j) {
                if (helper(coins, amount - j*coins[i], res)){
                    res+=j;
                    return true;
                }
                
            }
        }
        return false;
    }
    
};

//shaun 2nd round trying to use recursion to solve
//accepted after fixing 3 bugs
//runtime 440ms, faster than 7.3%, mem less than 8% 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        int res = helper(coins, amount);
        return res == INT_MAX? -1: res;
        
    }
private:
    unordered_map<int,int> memo;
    //bool helper --- bug 1, forgot to change from bool to int
    int helper(vector<int>& coins, int amount) {
        if (memo.count(amount)) return memo[amount];
        if (amount == 0) return 0;
        int res = INT_MAX;
        
        /* //TLE???   ---- bug 2, seems right, but TLE
        for (int i = 0; i < coins.size(); ++i) {
            for (int j = amount/coins[i]; j>=1; --j) {
                int res1 = helper(coins, amount - j*coins[i]);
                if (res1 != INT_MAX) {
                    res = min(res, res1 + j);
                }
            }
        }*/
        for (int i = 0; i < coins.size(); ++i) {
             if (coins[i] <= amount) {
             	int res1 = helper(coins, amount - coins[i]);
             	if (res1 != INT_MAX)
                	res = min(res,  res1 + 1);
             }
        }
        return memo[amount] = res;
    };
};

