//yuanbin c++ Your submission beats 100.00% Submissions!
class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        if (n < 1) {
            return 0;
        }
        

        int ret0 = 1, ret1 = 1, ret2 = 1;

        for (int i = 2; i != n + 1; ++i) {
            ret0 = ret1 + ret2;
            ret2 = ret1;
            ret1 = ret0;
        }

        return ret0;
    }
};
