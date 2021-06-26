/*
grandyang idea, draw a picture to figure out 1D case
find all x condinates, sort it, find min distance 1D for x 
2D is simply combination of 1D

shaun java code
Runtime: 7 ms, faster than 59.44% of Java online submissions for Best Meeting Point.
Memory Usage: 26.8 MB, less than 42.99% of Java online submissions for Best Meeting Point.

*/
class Solution {
    public int minTotalDistance(int[][] grid) {
        List<Integer> y = new ArrayList<>(); //all y or row cordindates
        List<Integer> x = new ArrayList<>(); //store all x or col coordinates
        int m = grid.length, n = grid[0].length;
        for (int i = 0; i < m; ++i ){
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {  //is home
                    y.add(i);
                    x.add(j);
                }
            }
        }
        return minDist1D(y) + minDist1D(x); 
    }
    //find min distance for 1D case, use math
    private int minDist1D(List<Integer> x) {
        Collections.sort(x);
        int i = 0, j = x.size()-1, res = 0;
        while (i < j) {
            res += x.get(j--) - x.get(i++);
        }
        return res;
    }
}
