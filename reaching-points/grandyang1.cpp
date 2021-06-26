/*
grandyang 1, 
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Reaching Points.
Memory Usage: 9.3 MB, less than 7.41% of C++ online submissions for Reaching Points.
*/
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx >= sx && ty >= sy) {
            if (tx > ty) {
                if (ty == sy) return (tx - sx) % ty == 0;
                tx %= ty;
            } else {
                if (tx == sx) return (ty - sy) % tx == 0;
                else ty %= tx;
            }
        }
        return tx == sx && ty == sy;
    }
};

