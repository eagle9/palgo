/*
TLE

*/
class Solution {
    private int count = 0;
    public int change(int amount, int[] coins) {
        Arrays.sort(coins);
        helper(coins, 0, amount);
        return count;
    }
    
    
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
    public void helper(int[] coins, int start, int amount) {
        if (amount == 0) {
            count++;
            return;
        }
        //if (start == coins.size()) return;

        //try each coin fro start to last
        //bug 1 coins[i] < amount, should be <=
        for (int i = start; i < coins.length && coins[i] <= amount; ++i) {
            helper(coins, i, amount-coins[i]);
        }
    }

}
