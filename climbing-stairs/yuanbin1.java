//yuanbin c++ v1, Your submission beats 93.40% Submissions!
public class Solution {
    /**
     * @param n: An integer
     * @return: An integer
     */
    public int climbStairs(int n) {
        if (n < 1) {
            return 0;
        }
        if (n == 1) return 1;
        if (n == 2) return 2;

        int [] ret = new int[n + 1];
        ret[0] = 0;
        ret[1] = 1;
        ret[2] = 2;
        for (int i = 3; i <= n; i++) {
            //option1, get to i-1 first, ret[i-1] ways, +1 to get i
            //option2, get to i-2 first, 1+1 to get i, but this is included in option1
            //option2, get to i-2 first, +2 to get i,  so
            ret[i] = ret[i - 1] + ret[i - 2];
        }

        return ret[n];
    }
};
//Time: O(n), Space: O(n), but space can be reduced to O(1),check yuanbin2
