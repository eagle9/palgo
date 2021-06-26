/*
#beats 100.00%, https://lefttree.gitbooks.io/leetcode-categories/content/Math/mathWithoutOperator/divideTwoIntegers.html
#divide two integers without using multiplication, division and mod operator
#9/2
# 2 4 8 16 > 9, i = 3, doubling 3 times, over 9
#doubling 2 times to get 8,   9-8 = 1,   1 < 2 the divisor, done. 
# result = 1 << 2 = 4
# 44/3,   3-6-12-24... 48,  res = 0+3,  res = 1<<3 = 8, dividend = 44-24 = 20
# 20/3,   3-6-12..24 ,   res = 8+1<<2 = 12, divident = 20- 12 = 8
# 8/3,  3-6..12,   res = 12  + 1<<1 = 14, divdend = 8 - 6= 2 < 3 the divisor
#    final result = 14 

*/
//beats 97.80%
public class Solution {
    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    public int divide(int dividend, int divisor) {
        int sign = 1;
        if (((dividend > 0)  && (divisor < 0)) ||((dividend < 0  && divisor > 0)))
            sign = -1;
        if (dividend == 0) return 0;
        if (divisor == 0) return Integer.MAX_VALUE;
        //add the following for java
        
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }
        
        //dividend = Math.abs(dividend);
        //divisor = Math.abs(divisor);
        long dividend1 = Math.abs((long)dividend);
        long divisor1 = Math.abs((long)divisor);
        int res = 0;
        while (dividend1 >= divisor1) {
            int i = 0; //times of doubling divisor
            long d = divisor1;
            while (d <= dividend1) {
                d = d << 1;
                i++;
            }
            //10/3 :  d=3, i=0; d=6, i=1; d=12, i=2;
            //res = 1<<1 = 2, dividend -= 6 = 4
            //4/3, d=3, i=0; d=6, i=1; res = 2+ 1<<0 = 3, dividend = 4-3=1
            //d > dividend, times of doubling that's less than divident is i-1  !!!!
            res += 1 << (i-1);  //1<<i that's wrong,  i-1 should be inside () !!!
            //dividend1 -= divisor << (i-1);
            dividend1 -=  d >>1;
        }
        
        if (sign < 0) res = -res;
        
        if (res > Integer.MAX_VALUE)
            res = Integer.MAX_VALUE;
            
        return res;
    }
}



        
