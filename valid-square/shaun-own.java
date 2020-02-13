/*
init idea for 4min, no progress, 
no order 
with order , pretty easy, 
if no rotation, easy, 
with rotation

then calc edge and sort and check
shaun's own idea with corner case debugging
Runtime: 1 ms, faster than 83.47% of Java online submissions for Valid Square.
Memory Usage: 38 MB, less than 12.50% of Java online submissions for Valid Square.
*/

class Solution {
    public boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {
        return helper(p1,p2,p3,p4) && helper(p2,p1,p3,p4) &&
            helper(p3,p1,p2,p4) && helper(p4,p1,p2,p3);
    }
    public boolean helper(int[] p1, int[] p2, int[] p3, int[] p4) {
        //p1 to p2 distance square
        int edge2 = d2(p1,p2);
        int edge3 = d2(p1,p3);
        int edge4 = d2(p1,p4);
        int [] e = {edge2, edge3, edge4};
        Arrays.sort(e);
        if (e[2] == 0) return false; //corner case
        if (e[0] != e[1]) return false;
        if (e[0] + e[1] != e[2]) return false;
        return true;
    }
    private int d2(int [] p1, int [] p2) {
        return (p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]);
    }
}
