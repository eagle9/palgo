/*
Runtime: 156 ms, faster than 100.00% of C++ online submissions for Generate Random Point in a Circle.
Memory Usage: 27.4 MB, less than 76.47% of C++ online submissions for Generate Random Point in a Circle.
grandyang rejection sampling
translate to java leads to TLE
*/
class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        r = radius; centerX = x_center; centerY = y_center;
    }
    
    vector<double> randPoint() {
        //int rand(void ) Returns a pseudo-random integral number in the range between 0 and RAND_MAX.

        while (true) {
            double x = (2 * (double)rand() / RAND_MAX - 1.0) * r;
            double y = (2 * (double)rand() / RAND_MAX - 1.0) * r;
            if (x * x + y * y <= r * r) return {centerX + x, centerY + y};
        }
    }

private:
    double r, centerX, centerY;
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
