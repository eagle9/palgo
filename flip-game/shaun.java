public class Solution {
    /**
     * @param s: the given string
     * @return: all the possible states of the string after one valid move
     */
     //grandyang idea, shaun glanced and coded, beats 100%
     //key point:   restore the change, think 3 times about details
    public List<String> generatePossibleNextMoves(String s) {
        // write your code here
        
        int len = s.length();
        char [] a = s.toCharArray();
        List<String> res = new ArrayList<>();
        for (int i =1; i < a.length; i++) {
            
            if (a[i-1] == '+' && a[i] == '+') {
                a[i-1] ='-';
                a[i] = '-';
                String state = String.valueOf(a);
                res.add(state);
                a[i-1] = '+';
                a[i] = '+'; //restore ai for next step
            }
        }
        return res;
    }
}
