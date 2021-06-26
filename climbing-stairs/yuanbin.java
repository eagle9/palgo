//yuanbin v2,c++ Your submission beats 100.00% Submissions!
//yuanbin v2, java, Time O(n), space just O(1)，beats 99.00% Submissions. 
public class Solution {
    /**
     * @param n: An integer
     * @return: An integer
     */
    public int climbStairs(int n) {
        if (n < 1) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
        int ret1 = 1, ret2 = 2;
        int ret = 0;
        for (int i = 3; i <= n; i++) {
            ret = ret1 + ret2;
            ret1 = ret2; //update ret1 first
            ret2 = ret;
            
        }
        return ret;
    }
};
