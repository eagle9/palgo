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
        if (ln < 0) { //make ln positive, n can be negative
            x = 1 / x;
            ln = -ln;
        }
        double result = 1;
		//basic, x * x * x ... * x, n times
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
   	//grandyang, beats 68%,
    double myPow(double x, int n) {
        if (n < 0) return 1 / power(x, -n);
        return power(x, n);
    }
    double power(double x, int n) {
        if (n == 0) return 1;
        double half = power(x, n / 2);
        if (n % 2 == 0) return half * half;
        return x * half * half;
    } 
    
};
