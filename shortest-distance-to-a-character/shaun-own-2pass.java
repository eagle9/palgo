/*
shaun own idea with two pass O(n)
may 2020
accepted after 1 bug fix, test test test, even trace your program
Runtime: 1 ms, faster than 98.51% of Java online submissions for Shortest Distance to a Character.
Memory Usage: 39.5 MB, less than 6.45% of Java online submissions for Shortest Distance to a Character.
*/
class Solution {
    public int[] shortestToChar(String S, char C) {
        char [] chars = S.toCharArray();
        int [] res = new int[chars.length];
        Arrays.fill(res, Integer.MAX_VALUE);
        
        int dist = chars.length+2;  //Integer.MAV_VALUE bug, could overflow and turn negative
        //iterate from left to right
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == C) {
                res[i] = 0;
                dist = 0;
            }else {
                dist++;
                res[i] = Math.min(res[i], dist);
            }
        }
        dist = chars.length+2;
        for (int i = chars.length-1; i >=0; i--) {
            if (chars[i] == C) {
                res[i] = 0;
                dist = 0;
            }else {
                dist++;
                res[i] = Math.min(res[i], dist);
            }
        }
        return res;
        
    }
}
