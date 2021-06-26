//shaun own dfs, accepted after fixing 1 bug, TLE
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        helper(coins, 0, amount);
        return count;
    }
private:
    int count = 0;
    /*test
          h(0,5)
          1/
        h(125,4)   h(25,2)   h(5,0)
      1/ 2\
h(125,3) h(25,2)
    1/
h(125,2)
   1/   2\
h(125,1) h(25,0)
  1/
h(125,0)
    */
    void helper(vector<int>& coins, int start, int amount) {
        if (amount == 0) {
            count++;
            return;
        }
        //if (start == coins.size()) return;
        
        //try each coin fro start to last
        //bug 1 coins[i] < amount, should be <=
        for (int i = start; i < coins.size() && coins[i] <= amount; ++i) {
            helper(coins, i, amount-coins[i]);
        }
    }
};


/*
idea forming
          125,5
       1/        2\          5\
   125,4       125,3        125,0
   1/    \2        2|
  125,3   125,2       125,1
 1/     \2       1/X
125,2     125,1  125,0
1/   \2      1/X
125,1 125,0  125,0
1/
125,0
->11111
->1112
->122
->5
how to avoid repetition, yes only chose >= coin

*/
