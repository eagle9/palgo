//jiadai c++ --> java, beats 87.00%
public class Solution {
    /*
     * @param x: the base number
     * @param n: the power number
     * @return: the result
     */
    public double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        long ln = n; //to prevent overflow
        if (ln < 0) { //make ln positive
            x = 1 / x;
            ln = -ln;
        }
        double result = 1;
        while (ln != 0) {
            if (ln % 2 == 1) {
                result *= x;
            }
            //x ^(ln) ----> (x*x) ^ (ln/2), this is the main idea
            x *= x;
            ln >>= 1;
        }

        return result;
    }
    
    
};
