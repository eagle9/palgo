public class Solution {
    /**
     * @param s: the given string
     * @return: if the starting player can guarantee a win
     */
     
     //grandyang idea, shaun came to the same idea, shaun own code, beats 68%
     //key point: find the recursion accurate and make sure correct
     //recursion is hard to analyze its complexity
     //okay to analze,   n-ary tree, depth = ??? n, so T= O(n^n)
    public boolean canWin(String s) {
        // write your code here
        char [] a = s.toCharArray();
        
        for (int i =1; i < a.length; i++) {
            
            if (a[i-1] == '+' && a[i] == '+') {
                a[i-1] ='-';
                a[i] = '-';
                //use substring to constuct next state is okay too
                String state = String.valueOf(a);
                //opponent now starts with state, can he win? i win when he lose....
                if (!canWin(state))
                    return true;
                a[i-1] = '+';
                a[i] = '+'; //restore ai for next step
            }
        }
        
        //no way found to win
        return false;
    }
}
