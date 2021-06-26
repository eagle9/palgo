/*

Runtime: 157 ms, faster than 20.16% of Java online submissions for Generate Random Point in a Circle.
Memory Usage: 48.8 MB, less than 100.00% of Java online submissions for Generate Random Point in a Circle.

*/
class Solution {

    public Solution(double radius, double x_center, double y_center) {
        this.r = radius; this.centerX = x_center; this.centerY = y_center;
        rand = new Random();
    }
    
    public double[] randPoint() {
         while (true) {
            double x = (2*rand.nextDouble() - 1.0)*r;
            double y = (2*rand.nextDouble() - 1.0)*r;
            if (x * x + y * y <= r * r) return new double[]{centerX + x, centerY + y};
        }
    }
    double r, centerX, centerY;
    Random rand;
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * double[] param_1 = obj.randPoint();
 */
/*
Runtime: 156 ms, faster than 100.00% of C++ online submissions for Generate Random Point in a Circle.
Memory Usage: 27.4 MB, less than 76.47% of C++ online submissions for Generate Random Point in a Circle.
grandyang rejection sampling
translate to java leads to TLE
*/


